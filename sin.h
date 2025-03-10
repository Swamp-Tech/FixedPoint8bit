/*
Таблица косинусов от 0 градусов до (255/256) * 90 градусов 
с шагом (1/256) * 90 градусов

cosines [binary_angle] = cos (x)
x - угол в градусах
x = (binary_angle / 256) * 90
Пример:
cosines [1] = cos (0.3515625) = cos ( 90*(1/256) ) ~= (255/256)

// В комментариях угол в градусах
*/
const uint8_t sinus[] = {
        0, // sin (0.0) 0
        2, // sin (0.3515625) 1
        3, // sin (0.703125) 2
        5, // sin (1.0546875) 3
        6, // sin (1.40625) 4
        8, // sin (1.7578125) 5
        9, // sin (2.109375) 6
        11, // sin (2.4609375) 7
        13, // sin (2.8125) 8
        14, // sin (3.1640625) 9
        16, // sin (3.515625) 10
        17, // sin (3.8671875) 11
        19, // sin (4.21875) 12
        20, // sin (4.5703125) 13
        22, // sin (4.921875) 14
        24, // sin (5.2734375) 15
        25, // sin (5.625) 16
        27, // sin (5.9765625) 17
        28, // sin (6.328125) 18
        30, // sin (6.6796875) 19
        31, // sin (7.03125) 20
        33, // sin (7.3828125) 21
        34, // sin (7.734375) 22
        36, // sin (8.0859375) 23
        38, // sin (8.4375) 24
        39, // sin (8.7890625) 25
        41, // sin (9.140625) 26
        42, // sin (9.4921875) 27
        44, // sin (9.84375) 28
        45, // sin (10.1953125) 29
        47, // sin (10.546875) 30
        48, // sin (10.8984375) 31
        50, // sin (11.25) 32
        51, // sin (11.6015625) 33
        53, // sin (11.953125) 34
        55, // sin (12.3046875) 35
        56, // sin (12.65625) 36
        58, // sin (13.0078125) 37
        59, // sin (13.359375) 38
        61, // sin (13.7109375) 39
        62, // sin (14.0625) 40
        64, // sin (14.4140625) 41
        65, // sin (14.765625) 42
        67, // sin (15.1171875) 43
        68, // sin (15.46875) 44
        70, // sin (15.8203125) 45
        71, // sin (16.171875) 46
        73, // sin (16.5234375) 47
        74, // sin (16.875) 48
        76, // sin (17.2265625) 49
        77, // sin (17.578125) 50
        79, // sin (17.9296875) 51
        80, // sin (18.28125) 52
        82, // sin (18.6328125) 53
        83, // sin (18.984375) 54
        85, // sin (19.3359375) 55
        86, // sin (19.6875) 56
        88, // sin (20.0390625) 57
        89, // sin (20.390625) 58
        91, // sin (20.7421875) 59
        92, // sin (21.09375) 60
        94, // sin (21.4453125) 61
        95, // sin (21.796875) 62
        97, // sin (22.1484375) 63
        98, // sin (22.5) 64
        99, // sin (22.8515625) 65
        101, // sin (23.203125) 66
        102, // sin (23.5546875) 67
        104, // sin (23.90625) 68
        105, // sin (24.2578125) 69
        107, // sin (24.609375) 70
        108, // sin (24.9609375) 71
        109, // sin (25.3125) 72
        111, // sin (25.6640625) 73
        112, // sin (26.015625) 74
        114, // sin (26.3671875) 75
        115, // sin (26.71875) 76
        117, // sin (27.0703125) 77
        118, // sin (27.421875) 78
        119, // sin (27.7734375) 79
        121, // sin (28.125) 80
        122, // sin (28.4765625) 81
        123, // sin (28.828125) 82
        125, // sin (29.1796875) 83
        126, // sin (29.53125) 84
        128, // sin (29.8828125) 85
        129, // sin (30.234375) 86
        130, // sin (30.5859375) 87
        132, // sin (30.9375) 88
        133, // sin (31.2890625) 89
        134, // sin (31.640625) 90
        136, // sin (31.9921875) 91
        137, // sin (32.34375) 92
        138, // sin (32.6953125) 93
        140, // sin (33.046875) 94
        141, // sin (33.3984375) 95
        142, // sin (33.75) 96
        144, // sin (34.1015625) 97
        145, // sin (34.453125) 98
        146, // sin (34.8046875) 99
        147, // sin (35.15625) 100
        149, // sin (35.5078125) 101
        150, // sin (35.859375) 102
        151, // sin (36.2109375) 103
        152, // sin (36.5625) 104
        154, // sin (36.9140625) 105
        155, // sin (37.265625) 106
        156, // sin (37.6171875) 107
        157, // sin (37.96875) 108
        159, // sin (38.3203125) 109
        160, // sin (38.671875) 110
        161, // sin (39.0234375) 111
        162, // sin (39.375) 112
        164, // sin (39.7265625) 113
        165, // sin (40.078125) 114
        166, // sin (40.4296875) 115
        167, // sin (40.78125) 116
        168, // sin (41.1328125) 117
        170, // sin (41.484375) 118
        171, // sin (41.8359375) 119
        172, // sin (42.1875) 120
        173, // sin (42.5390625) 121
        174, // sin (42.890625) 122
        175, // sin (43.2421875) 123
        177, // sin (43.59375) 124
        178, // sin (43.9453125) 125
        179, // sin (44.296875) 126
        180, // sin (44.6484375) 127
        181, // sin (45.0) 128
        182, // sin (45.3515625) 129
        183, // sin (45.703125) 130
        184, // sin (46.0546875) 131
        185, // sin (46.40625) 132
        186, // sin (46.7578125) 133
        188, // sin (47.109375) 134
        189, // sin (47.4609375) 135
        190, // sin (47.8125) 136
        191, // sin (48.1640625) 137
        192, // sin (48.515625) 138
        193, // sin (48.8671875) 139
        194, // sin (49.21875) 140
        195, // sin (49.5703125) 141
        196, // sin (49.921875) 142
        197, // sin (50.2734375) 143
        198, // sin (50.625) 144
        199, // sin (50.9765625) 145
        200, // sin (51.328125) 146
        201, // sin (51.6796875) 147
        202, // sin (52.03125) 148
        203, // sin (52.3828125) 149
        204, // sin (52.734375) 150
        205, // sin (53.0859375) 151
        206, // sin (53.4375) 152
        207, // sin (53.7890625) 153
        207, // sin (54.140625) 154
        208, // sin (54.4921875) 155
        209, // sin (54.84375) 156
        210, // sin (55.1953125) 157
        211, // sin (55.546875) 158
        212, // sin (55.8984375) 159
        213, // sin (56.25) 160
        214, // sin (56.6015625) 161
        215, // sin (56.953125) 162
        215, // sin (57.3046875) 163
        216, // sin (57.65625) 164
        217, // sin (58.0078125) 165
        218, // sin (58.359375) 166
        219, // sin (58.7109375) 167
        220, // sin (59.0625) 168
        220, // sin (59.4140625) 169
        221, // sin (59.765625) 170
        222, // sin (60.1171875) 171
        223, // sin (60.46875) 172
        224, // sin (60.8203125) 173
        224, // sin (61.171875) 174
        225, // sin (61.5234375) 175
        226, // sin (61.875) 176
        227, // sin (62.2265625) 177
        227, // sin (62.578125) 178
        228, // sin (62.9296875) 179
        229, // sin (63.28125) 180
        229, // sin (63.6328125) 181
        230, // sin (63.984375) 182
        231, // sin (64.3359375) 183
        231, // sin (64.6875) 184
        232, // sin (65.0390625) 185
        233, // sin (65.390625) 186
        233, // sin (65.7421875) 187
        234, // sin (66.09375) 188
        235, // sin (66.4453125) 189
        235, // sin (66.796875) 190
        236, // sin (67.1484375) 191
        237, // sin (67.5) 192
        237, // sin (67.8515625) 193
        238, // sin (68.203125) 194
        238, // sin (68.5546875) 195
        239, // sin (68.90625) 196
        239, // sin (69.2578125) 197
        240, // sin (69.609375) 198
        241, // sin (69.9609375) 199
        241, // sin (70.3125) 200
        242, // sin (70.6640625) 201
        242, // sin (71.015625) 202
        243, // sin (71.3671875) 203
        243, // sin (71.71875) 204
        244, // sin (72.0703125) 205
        244, // sin (72.421875) 206
        245, // sin (72.7734375) 207
        245, // sin (73.125) 208
        245, // sin (73.4765625) 209
        246, // sin (73.828125) 210
        246, // sin (74.1796875) 211
        247, // sin (74.53125) 212
        247, // sin (74.8828125) 213
        248, // sin (75.234375) 214
        248, // sin (75.5859375) 215
        248, // sin (75.9375) 216
        249, // sin (76.2890625) 217
        249, // sin (76.640625) 218
        249, // sin (76.9921875) 219
        250, // sin (77.34375) 220
        250, // sin (77.6953125) 221
        250, // sin (78.046875) 222
        251, // sin (78.3984375) 223
        251, // sin (78.75) 224
        251, // sin (79.1015625) 225
        252, // sin (79.453125) 226
        252, // sin (79.8046875) 227
        252, // sin (80.15625) 228
        252, // sin (80.5078125) 229
        253, // sin (80.859375) 230
        253, // sin (81.2109375) 231
        253, // sin (81.5625) 232
        253, // sin (81.9140625) 233
        254, // sin (82.265625) 234
        254, // sin (82.6171875) 235
        254, // sin (82.96875) 236
        254, // sin (83.3203125) 237
        254, // sin (83.671875) 238
        255, // sin (84.0234375) 239
        255, // sin (84.375) 240
        255, // sin (84.7265625) 241
        255, // sin (85.078125) 242
        255, // sin (85.4296875) 243
        255, // sin (85.78125) 244
        255, // sin (86.1328125) 245
        255, // sin (86.484375) 246
        255, // sin (86.8359375) 247
        255, // sin (87.1875) 248
        255, // sin (87.5390625) 249
        255, // sin (87.890625) 250
        255, // sin (88.2421875) 251
        255, // sin (88.59375) 252
        255, // sin (88.9453125) 253
        255, // sin (89.296875) 254
        255, // sin (89.6484375) 255
};