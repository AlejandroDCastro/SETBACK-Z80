ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 1.
Hexadecimal [16-Bits]



                              1 ;;;
                              2 ;;; File generated by cpct_aks2c CPCtelera script
                              3 ;;; Souce file of this conversion: music/menu.aks
                              4 ;;; Generation time: mar 03 nov 2020 22:30:26 CET
                              5 ;;;
                              6 
                              7 ;;; Set absolute memory addressing
                              8 .area __song_menu (ABS)
   0040                       9 .org 0x0040
                             10 
                             11 ;;; Music data start (403 bytes)
                             12 ;;;
   0040                      13 _song_menu::
   0040 41 54 31 30 01 40    14 .db 0x41, 0x54, 0x31, 0x30, 0x01, 0x40, 0x42, 0x0f, 0x02, 0x06, 0x61, 0x00, 0x58, 0x00, 0x61, 0x00
        42 0F 02 06 61 00
        58 00 61 00
   0050 67 00 6E 00 7D 00    15 .db 0x67, 0x00, 0x6e, 0x00, 0x7d, 0x00, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x5a
        98 00 00 00 00 00
        00 00 0D 5A
   0060 00 01 00 00 0D 5A    16 .db 0x00, 0x01, 0x00, 0x00, 0x0d, 0x5a, 0x00, 0x01, 0x00, 0x05, 0x38, 0x0d, 0x69, 0x00, 0x01, 0x00
        00 01 00 05 38 0D
        69 00 01 00
   0070 36 21 78 0C 30 68    17 .db 0x36, 0x21, 0x78, 0x0c, 0x30, 0x68, 0x0c, 0x20, 0x58, 0x0c, 0x0d, 0x70, 0x00, 0x01, 0x00, 0x7e
        0C 20 58 0C 0D 70
        00 01 00 7E
   0080 26 0C 7C 0A 74 09    18 .db 0x26, 0x0c, 0x7c, 0x0a, 0x74, 0x09, 0x74, 0x08, 0x70, 0x05, 0x70, 0x04, 0x6c, 0x03, 0x68, 0x02
        74 08 70 05 70 04
        6C 03 68 02
   0090 64 01 60 01 20 0D    19 .db 0x64, 0x01, 0x60, 0x01, 0x20, 0x0d, 0x5a, 0x00, 0x01, 0x00, 0x3e, 0x01, 0x3a, 0x01, 0x36, 0x01
        5A 00 01 00 3E 01
        3A 01 36 01
   00A0 2E 01 2A 01 22 01    20 .db 0x2e, 0x01, 0x2a, 0x01, 0x22, 0x01, 0x1a, 0x01, 0x12, 0x01, 0x0d, 0x5a, 0x00, 0x40, 0x00, 0x00
        1A 01 12 01 0D 5A
        00 40 00 00
   00B0 00 E0 00 00 E1 00    21 .db 0x00, 0xe0, 0x00, 0x00, 0xe1, 0x00, 0xe7, 0x00, 0xf2, 0x00, 0x00, 0x5d, 0x01, 0x94, 0x01, 0x9c
        E7 00 F2 00 00 5D
        01 94 01 9C
   00C0 01 00 F8 00 00 01    22 .db 0x01, 0x00, 0xf8, 0x00, 0x00, 0x01, 0x26, 0x01, 0x00, 0xf8, 0x00, 0x00, 0x01, 0x26, 0x01, 0x00
        26 01 00 F8 00 00
        01 26 01 00
   00D0 F8 00 00 01 26 01    23 .db 0xf8, 0x00, 0x00, 0x01, 0x26, 0x01, 0x00, 0xf8, 0x00, 0x00, 0x01, 0x26, 0x01, 0x01, 0xb3, 0x00
        00 F8 00 00 01 26
        01 01 B3 00
   00E0 00 8A E0 00 00 01    24 .db 0x00, 0x8a, 0xe0, 0x00, 0x00, 0x01, 0x00, 0x8e, 0xe0, 0x00, 0x00, 0x02, 0x3a, 0x42, 0x00, 0x02
        00 8E E0 00 00 02
        3A 42 00 02
   00F0 53 00 8A E0 00 00    25 .db 0x53, 0x00, 0x8a, 0xe0, 0x00, 0x00, 0x01, 0x00, 0x8e, 0xe0, 0x00, 0x00, 0x02, 0x3e, 0x53, 0x00
        01 00 8E E0 00 00
        02 3E 53 00
   0100 A6 E0 00 00 03 0E    26 .db 0xa6, 0xe0, 0x00, 0x00, 0x03, 0x0e, 0x79, 0x42, 0x00, 0x0c, 0x7b, 0x04, 0x42, 0x00, 0x79, 0x04
        79 42 00 0C 7B 04
        42 00 79 04
   0110 42 00 75 06 6B 06    27 .db 0x42, 0x00, 0x75, 0x06, 0x6b, 0x06, 0x71, 0x0e, 0x6b, 0x0e, 0x71, 0x06, 0x75, 0x04, 0x42, 0x00
        71 0E 6B 0E 71 06
        75 04 42 00
ASxxxx Assembler V02.00 + NoICE + SDCC mods  (Zilog Z80 / Hitachi HD64180), page 2.
Hexadecimal [16-Bits]



   0120 79 04 42 00 71 00    28 .db 0x79, 0x04, 0x42, 0x00, 0x71, 0x00, 0x72, 0xe0, 0x00, 0x00, 0x04, 0x42, 0x00, 0x42, 0x00, 0x42
        72 E0 00 00 04 42
        00 42 00 42
   0130 00 42 00 42 00 42    29 .db 0x00, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x02, 0x72, 0x60, 0x05, 0x0e, 0x72, 0x60, 0x04, 0x06
        00 02 72 60 05 0E
        72 60 04 06
   0140 33 06 72 60 05 02    30 .db 0x33, 0x06, 0x72, 0x60, 0x05, 0x02, 0x42, 0x00, 0x0a, 0x72, 0x60, 0x04, 0x0e, 0x72, 0x60, 0x05
        42 00 0A 72 60 04
        0E 72 60 05
   0150 0E 72 60 04 06 33    31 .db 0x0e, 0x72, 0x60, 0x04, 0x06, 0x33, 0x06, 0x72, 0x60, 0x05, 0x42, 0x00, 0x00, 0x72, 0xe0, 0x00
        06 72 60 05 42 00
        00 72 E0 00
   0160 00 04 42 00 42 00    32 .db 0x00, 0x04, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x02, 0x72
        42 00 42 00 42 00
        42 00 02 72
   0170 60 05 0E 72 60 04    33 .db 0x60, 0x05, 0x0e, 0x72, 0x60, 0x04, 0x06, 0x33, 0x06, 0x72, 0x60, 0x05, 0x02, 0x42, 0x00, 0x0a
        06 33 06 72 60 05
        02 42 00 0A
   0180 72 60 04 0E 72 60    34 .db 0x72, 0x60, 0x04, 0x0e, 0x72, 0x60, 0x05, 0x0e, 0x72, 0x60, 0x04, 0x06, 0x33, 0x06, 0x72, 0x60
        05 0E 72 60 04 06
        33 06 72 60
   0190 05 42 00 00 8E E0    35 .db 0x05, 0x42, 0x00, 0x00, 0x8e, 0xe0, 0x00, 0x00, 0x02, 0x3e, 0x53, 0x00, 0x72, 0xe0, 0x00, 0x00
        00 00 02 3E 53 00
        72 E0 00 00
   01A0 04 42 00 42 00 42    36 .db 0x04, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x42, 0x00, 0x02, 0x72, 0x60
        00 42 00 42 00 42
        00 02 72 60
   01B0 05 0E 72 60 04 06    37 .db 0x05, 0x0e, 0x72, 0x60, 0x04, 0x06, 0x33, 0x06, 0x72, 0x60, 0x05, 0x02, 0x42, 0x00, 0x0a, 0x72
        33 06 72 60 05 02
        42 00 0A 72
   01C0 60 04 0E 72 60 05    38 .db 0x60, 0x04, 0x0e, 0x72, 0x60, 0x05, 0x0e, 0x72, 0x60, 0x04, 0x06, 0x33, 0x06, 0x72, 0x60, 0x05
        0E 72 60 04 06 33
        06 72 60 05
   01D0 42 00 00             39 .db 0x42, 0x00, 0x00
