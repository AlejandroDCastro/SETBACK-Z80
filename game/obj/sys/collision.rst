ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 1.
Hexadecimal [16-Bits]



                              1 ;; This file is part of SETBACK.
                              2 ;; Copyright (C) 2020 TCore (@TCore14)
                              3 ;;
                              4 ;; This program is free software: you can redistribute it and/or modify
                              5 ;; it under the terms of the GNU General Public License as published by
                              6 ;; the Free Software Foundation, either version 3 of the License, or
                              7 ;; (at your option) any later version.
                              8 ;;
                              9 ;; This program is distributed in the hope that it will be useful,
                             10 ;; but WITHOUT ANY WARRANTY; without even the implied warranty of
                             11 ;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
                             12 ;; GNU General Public License for more details.
                             13 ;;
                             14 ;; You should have received a copy of the GNU General Public License
                             15 ;; along with this program.  If not, see https://www.gnu.org/licenses/.
                             16 
                             17 ;;
                             18 ;; PHYSICS COLLISION
                             19 ;;
                             20 
ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 2.
Hexadecimal [16-Bits]



                             21 .include "man/entity.h.s"
                              1 ;; This file is part of SETBACK.
                              2 ;; Copyright (C) 2020 TCore (@TCore14)
                              3 ;;
                              4 ;; This program is free software: you can redistribute it and/or modify
                              5 ;; it under the terms of the GNU General Public License as published by
                              6 ;; the Free Software Foundation, either version 3 of the License, or
                              7 ;; (at your option) any later version.
                              8 ;;
                              9 ;; This program is distributed in the hope that it will be useful,
                             10 ;; but WITHOUT ANY WARRANTY; without even the implied warranty of
                             11 ;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
                             12 ;; GNU General Public License for more details.
                             13 ;;
                             14 ;; You should have received a copy of the GNU General Public License
                             15 ;; along with this program.  If not, see https://www.gnu.org/licenses/.
                             16 
                             17 ;;
                             18 ;; ENTITY MANAGER
                             19 ;;
                             20 
                             21 
                             22 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             23 ;;;;;;;;;;; FUNCIONES PUBLICAS ;;;;;;;;;;;;;;;
                             24 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             25 
                             26 .globl man_entity_init
                             27 .globl man_entity_create
                             28 .globl man_entity_getPlayer_IX
                             29 .globl man_entity_get_from_idx_IY
                             30 .globl man_entity_update_forall
                             31 .globl man_entity_update_forall_matching
                             32 .globl man_entity_calculate_screen_position
                             33 .globl man_entity_set4destruction
                             34 .globl man_entity_destroy_one
                             35 .globl man_entity_empty_array
                             36 
                             37 
                             38 
                             39 
                             40 
                             41 
                             42 
                             43 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             44 ;;;;;;;;;;; DEFINICIONES MACROS ;;;;;;;;;;;;;;
                             45 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             46 
                             47 ;; Entity definicion anonima de macro
                             48 .macro DefineEntityAnnonimous _type, _x, _y, _vx, _vy, _w, _h, _sprite, _jump, _lastPtr, _state, _walking, _distance
                             49    .db _type
                             50    .db _x
                             51    .db _y
                             52    .db _vx
                             53    .db _vy
                             54    .db _w
ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 3.
Hexadecimal [16-Bits]



                             55    .db _h
                             56    .dw _sprite
                             57    .db _jump
                             58    .dw _lastPtr
                             59    .db _state        ; Lo usamos para saber cuando una plataforma deja de renderizarse (Arreglamos el trozo que no se pintaba de la plataforma)
                             60                      ; y para guardar la ultima direccion pulsada por el player para moverse (Cambiar la animacion)
                             61    .db _walking      ; y para guardar el estado de la IA de los enemigos
                             62    .db _distance     ; Maxima distancia recorrida por los enemigos
                             63                      ; y booleano para comprobar si es una plataforma o una estrella
                             64 .endm
                             65 
                             66 
                             67 ;; Definimos una entidad identificada por su etiqueta nombre
                             68 .macro DefineEntity _name, _type, _x, _y, _vx, _vy, _w, _h, _sprite, _jump, _lastPtr, _state, _walking, _distance
                             69 _name::
                             70    DefineEntityAnnonimous _type, _x, _y, _vx, _vy, _w, _h, _sprite, _jump, _lastPtr, _state, _walking, _distance
                             71 .endm
                             72 
                             73 
                             74 ;; Definimos un array de entidades anonimas
                             75 .macro DefineEntityArray _name, _N
                             76 _name::
                             77    .rept _N
                             78       DefineEntityAnnonimous 0x00, 0xDE, 0xAD, 0xDE, 0xAD, 0xDE, 0xAD, 0xDE00, 0xAD, 0xC000, 0x00, 0x00, 0x00
                             79    .endm
                             80 .endm
                             81 
                             82 
                             83 
                             84 
                             85 
                             86 
                             87 
                             88 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             89 ;;;;;;;;;;; TIPOS DE ENTIDADES ;;;;;;;;;;;;;;;
                             90 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             91 
                             92 ;; Numero de bits para la mascara
                     0007    93 e_type_alive_bit    = 7
                     0006    94 e_type_physics_bit  = 6
                     0005    95 e_type_render_bit   = 5
                     0004    96 e_type_collider_bit = 4
                     0003    97 e_type_input_bit    = 3
                     0002    98 e_type_dead_bit     = 2
                     0001    99 e_type_portal_bit   = 1
                            100 
                            101 ;; Tipos de entidades (mascaras)
                     0000   102 e_type_invalid      = 0x00
                     0080   103 e_type_alive_mask   = (1 << e_type_alive_bit)
                     0040   104 e_type_physics_mask = (1 << e_type_physics_bit)
                     0020   105 e_type_render_mask  = (1 << e_type_render_bit)
                     0010   106 e_type_collide_mask = (1 << e_type_collider_bit)
                     0008   107 e_type_input_mask   = (1 << e_type_input_bit)
                     0004   108 e_type_dead_mask    = (1 << e_type_dead_bit)
                     0002   109 e_type_portal_mask  = (1 << e_type_portal_bit)
ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 4.
Hexadecimal [16-Bits]



                            110 
                            111 
                            112 ;; Entidades especificas
                     0070   113 e_type_character = e_type_physics_mask | e_type_collide_mask | e_type_render_mask
                     0078   114 e_type_player    = e_type_character | e_type_input_mask
                     0010   115 e_type_trap      = e_type_collide_mask
                     0018   116 e_type_platform  = e_type_trap | e_type_input_mask
                     00B0   117 e_type_enemy     = e_type_trap | e_type_alive_mask | e_type_render_mask
                     0012   118 e_type_portal    = e_type_trap | e_type_portal_mask
                     0019   119 e_type_star      = e_type_platform | 1
                            120 
                            121 
                            122 
                            123 
                            124 
                            125 
                            126 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                            127 ;;;;;;;;;;;;;;; CONSTANTES ;;;;;;;;;;;;;;;;;;;
                            128 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                            129 
                            130 ;; Constantes para posicionar cada componente de la entidad usando los registros IX e IY
                     0000   131 e_type     = 0
                     0001   132 e_x        = 1
                     0002   133 e_y        = 2
                     0003   134 e_vx       = 3
                     0004   135 e_vy       = 4
                     0005   136 e_w        = 5
                     0006   137 e_h        = 6
                     0007   138 e_sp_l     = 7
                     0008   139 e_sp_h     = 8
                     0009   140 e_jump     = 9
                     000A   141 e_lastPtr  = 10
                     000C   142 e_state    = 12
                     000D   143 e_walking  = 13
                     000E   144 e_distance = 14
                     000F   145 sizeof_e   = 15
ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 5.
Hexadecimal [16-Bits]



                             22 .include "input.h.s"
                              1 ;; This file is part of SETBACK.
                              2 ;; Copyright (C) 2020 TCore (@TCore14)
                              3 ;;
                              4 ;; This program is free software: you can redistribute it and/or modify
                              5 ;; it under the terms of the GNU General Public License as published by
                              6 ;; the Free Software Foundation, either version 3 of the License, or
                              7 ;; (at your option) any later version.
                              8 ;;
                              9 ;; This program is distributed in the hope that it will be useful,
                             10 ;; but WITHOUT ANY WARRANTY; without even the implied warranty of
                             11 ;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
                             12 ;; GNU General Public License for more details.
                             13 ;;
                             14 ;; You should have received a copy of the GNU General Public License
                             15 ;; along with this program.  If not, see https://www.gnu.org/licenses/.
                             16 
                             17 ;;
                             18 ;; INPUT SYSTEM
                             19 ;;
                             20 
                             21 
                             22 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             23 ;;;;;;;;;;; FUNCIONES PUBLICAS ;;;;;;;;;;;;;;;
                             24 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             25 
                             26 ;.globl sys_input_init
                             27 .globl sys_input_update
                             28 
                             29 
                             30 
                             31 
                             32 
                             33 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             34 ;;;;;;;;;;;;;;; CONSTANTES ;;;;;;;;;;;;;;;;;;;
                             35 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
                             36 
                     FFFFFFF7    37 gravity_acc == -9           ; Aceleracion maxima de la gravedad
ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 6.
Hexadecimal [16-Bits]



                             23 
                             24 
                             25 
                             26 
                             27 ;; Comprueba la colision del personaje con una entidad pasada por parametro
                             28 ;; INPUTS
                             29 ;;      IX: Puntero a la entidad del player
                             30 ;;      IY: Puntero a la entidad con la que colisiona
                             31 ;; DESTROYS
                             32 ;;      A, BC, D
                             33 ;; RETURN
                             34 ;;      0
   4384                      35 sys_collision_update_one_entity::
                             36 
                             37     ;; COLISIONES BOUNDING BOX
                             38 
   4384                      39 _bounding_box_check:
                             40     ;; (x sprite 1 + anchura sprite 1) > x sprite 2
   4384 DD 7E 01      [19]   41     ld      a, e_x(ix)                                          ; Cargamos en A la posicion x del jugador
   4387 DD 86 05      [19]   42     add     e_w(ix)                                             ; Le sumamos su ancho
   438A 3D            [ 4]   43     dec     a                                                   ; Ajustamos la anchura del bounding box
   438B FD 96 01      [19]   44     sub     e_x(iy)
   438E 38 5B         [12]   45     jr      c, _no_collision                                    ; Si A - e_x(iy) < 0 No hay colision
                             46 
                             47     ;; (y sprite 1 + altura sprite 1) > y sprite 2
   4390 DD 7E 02      [19]   48     ld      a, e_y(ix)
   4393 DD 86 06      [19]   49     add     e_h(ix)
   4396 3D            [ 4]   50     dec     a
   4397 FD 96 02      [19]   51     sub     e_y(iy)
   439A 38 4F         [12]   52     jr      c, _no_collision
                             53 
                             54     ;; (x sprite 2 + anchura sprite 2) > x sprite 1
   439C FD 7E 01      [19]   55     ld      a, e_x(iy)
   439F FD 86 05      [19]   56     add     a, e_w(iy)
   43A2 DD 46 01      [19]   57     ld      b, e_x(ix)
   43A5 04            [ 4]   58     inc     b
   43A6 B8            [ 4]   59     cp      b
   43A7 38 42         [12]   60     jr      c, _no_collision
                             61 
                             62     ;; (y sprite 2 + altura sprite 2) > y sprite 1
   43A9 FD 7E 02      [19]   63     ld      a, e_y(iy)
   43AC FD 86 06      [19]   64     add     a, e_h(iy)
   43AF DD 46 02      [19]   65     ld      b, e_y(ix)
   43B2 04            [ 4]   66     inc     b
   43B3 B8            [ 4]   67     cp      b
   43B4 38 35         [12]   68     jr      c, _no_collision
                             69     
   43B6                      70 _si_colision:
                             71 
                             72     ;; Comprobamos si hemos colisionado con una plataforma
   43B6 FD 7E 00      [19]   73     ld      a, e_type(iy)                                       ; A = Entity type
   43B9 E6 18         [ 7]   74     and     #e_type_platform                                    ; Comprobamos si el tipo es exactamente una plataforma
   43BB D6 18         [ 7]   75     sub     #e_type_platform
   43BD 20 16         [12]   76     jr     nz, _destroy_entity                                  ; Si no es = 0 el player pierde vida porque es una enemigo o trampa
                             77     ;; PLATAFORMA DETECTADA
ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 7.
Hexadecimal [16-Bits]



                             78 
                             79     ;; Comprobamos si la plataforma es colisionable o es de ambiente
   43BF FD 7E 00      [19]   80     ld      a, e_type(iy)
   43C2 E6 01         [ 7]   81     and     #1                                                  ; Comprobamos si tiene la marca de entidad de ambiente
   43C4 CC F7 43      [17]   82     call    z, sys_collision_correct_position                   ; Si no la tiene entonce corrige la posicion a la plataforma
   43C7 FD 36 0C 01   [19]   83     ld      e_state(iy), #1                                     ; Marcamos la entidad que esta colisionando
                             84     
                             85     ;; Marcamos la entidad para renderizar
   43CB                      86 _platform_detected:
   43CB FD 7E 00      [19]   87     ld      a, e_type(iy)
   43CE F6 20         [ 7]   88     or      #e_type_render_mask                                 ; Le asociamos la componente de render
   43D0 FD 77 00      [19]   89     ld      e_type(iy), a
   43D3 18 21         [12]   90     jr      _no_collision_check
                             91     
   43D5                      92 _destroy_entity:
                             93 
                             94     ;; Comprobamos si hemos colisionado con el portal
   43D5 FD 7E 00      [19]   95     ld      a, e_type(iy)
   43D8 EE 12         [ 7]   96     xor     #e_type_portal                                      ; XOR con el portal
   43DA 20 06         [12]   97     jr     nz, _destroy_player                                  ; if A=0
   43DC FD 36 00 04   [19]   98     ld      e_type(iy), #e_type_dead_mask                       ; Destruimos portal y pasamos de nivel
   43E0 18 14         [12]   99     jr      _no_collision_check
   43E2                     100 _destroy_player:
   43E2 DD 36 00 04   [19]  101     ld      e_type(ix), #e_type_dead_mask                       ; e_type = e_type_dead_mask para el player
   43E6 CD 87 48      [17]  102     call    man_entity_set4destruction                          ; Marcamos la trampa como muerta y renderizable tambien
   43E9 18 0B         [12]  103     jr      _no_collision_check
                            104 
   43EB                     105 _no_collision:
                            106 
   43EB FD 7E 0C      [19]  107     ld      a, e_state(iy)
   43EE 3D            [ 4]  108     dec     a
   43EF C0            [11]  109     ret    nz
   43F0 FD 36 0C 00   [19]  110     ld      e_state(iy), #0
   43F4 18 D5         [12]  111     jr      _platform_detected
   43F6                     112 _no_collision_check:
   43F6 C9            [10]  113     ret
                            114 
                            115 
                            116 
                            117 
                            118 
                            119 
                            120 ;; Corrige la posicion del personaje colisionado con respecto a la otra entidad para caer sobre una plataforma
                            121 ;; INPUTS
                            122 ;;      IY: Puntero a la entidad con la que colisiona
                            123 ;;      HL: Posicion anterior de la entidad (h=y and l=x)
                            124 ;; DESTROYS
                            125 ;;      0
                            126 ;; RETURN
                            127 ;;      0
   43F7                     128 sys_collision_correct_position::
                            129 
                            130     ;; Comprobamos que el personaje se situa arriba de la plataforma
   43F7 DD 7E 02      [19]  131     ld      a, e_y(ix)
                            132     ;add     a, e_h(ix)
ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 8.
Hexadecimal [16-Bits]



   43FA FD 46 02      [19]  133     ld      b, e_y(iy)
   43FD B8            [ 4]  134     cp      b
   43FE 30 18         [12]  135     jr     nc, finish_check
                            136 
                            137     ;; Comprobamos que la gravedad es positiva (hacia abajo)
   4400 3E F7         [ 7]  138     ld      a, #gravity_acc
   4402 DD 86 04      [19]  139     add     e_vy(ix)
   4405 38 11         [12]  140     jr      c, finish_check
                            141 
                            142     ;; Corregimos la posicion del personaje
   4407                     143 correct_top:
   4407 FD 7E 02      [19]  144     ld      a, e_y(iy)
   440A DD 96 06      [19]  145     sub     e_h(ix)
   440D DD 77 02      [19]  146     ld      e_y(ix), a
   4410 DD 36 04 00   [19]  147     ld      e_vy(ix), #0
   4414 DD 36 09 01   [19]  148     ld      e_jump(ix), #1
                            149     
   4418                     150 finish_check:
   4418 C9            [10]  151     ret
                            152 
                            153 
                            154 
                            155 
                            156 
                            157 
                            158 
                            159 ;; Comprueba la colision del personaje con las demas entidades
                            160 ;; INPUTS
                            161 ;;      IX: Puntero a la entidad a dibujar
                            162 ;; DESTROYS
                            163 ;;      A, BC, DE
                            164 ;; RETURN
                            165 ;;      HL: Posicion anterior
   4419                     166 sys_collision_update::
                            167 
                            168     ;; Colision del personaje con las plataformas, trampas y enemigos
   4419 21 84 43      [10]  169     ld      hl, #sys_collision_update_one_entity                ; Guardamos en IY un puntero a la rutina
   441C 3E 10         [ 7]  170     ld       a, #e_type_collide_mask                            ; Actualizamos la colision con las plataformas
   441E CD 63 48      [17]  171     call    man_entity_update_forall_matching                   ; Llamamos a la funcion de actualizar
                            172 
   4421 C9            [10]  173     ret
