/* Tunguska, ternary virtual machine
 *
 * Copyright (C) 2007,2008 Viktor Lofgren
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/* This is grade A compiler abuse. The compiler doesn't understand balanced
 * nonary. And runtime conversion is expensive as hell. Solution, create macros.
 * Create lots and lots of macros. */

#ifndef values_h
#define values_h

// Plain-Old-Data WORD to INT
#define PODWORD_TO_INT(HIGH, LOW) (LOW) + 729*(HIGH)

// The compiler is not smart enough to cache constructions like
// int foo = tryte::word_to_int("032", "DAB")
// 
// which is why it's about twice as fast to use
// PODWORD_TO_INT(TV_032, TV_DAB)

#define TV_DDD -364
#define TV_DDC -363
#define TV_DDB -362
#define TV_DDA -361
#define TV_DD0 -360
#define TV_DD1 -359
#define TV_DD2 -358
#define TV_DD3 -357
#define TV_DD4 -356
#define TV_DCD -355
#define TV_DCC -354
#define TV_DCB -353
#define TV_DCA -352
#define TV_DC0 -351
#define TV_DC1 -350
#define TV_DC2 -349
#define TV_DC3 -348
#define TV_DC4 -347
#define TV_DBD -346
#define TV_DBC -345
#define TV_DBB -344
#define TV_DBA -343
#define TV_DB0 -342
#define TV_DB1 -341
#define TV_DB2 -340
#define TV_DB3 -339
#define TV_DB4 -338
#define TV_DAD -337
#define TV_DAC -336
#define TV_DAB -335
#define TV_DAA -334
#define TV_DA0 -333
#define TV_DA1 -332
#define TV_DA2 -331
#define TV_DA3 -330
#define TV_DA4 -329
#define TV_D0D -328
#define TV_D0C -327
#define TV_D0B -326
#define TV_D0A -325
#define TV_D00 -324
#define TV_D01 -323
#define TV_D02 -322
#define TV_D03 -321
#define TV_D04 -320
#define TV_D1D -319
#define TV_D1C -318
#define TV_D1B -317
#define TV_D1A -316
#define TV_D10 -315
#define TV_D11 -314
#define TV_D12 -313
#define TV_D13 -312
#define TV_D14 -311
#define TV_D2D -310
#define TV_D2C -309
#define TV_D2B -308
#define TV_D2A -307
#define TV_D20 -306
#define TV_D21 -305
#define TV_D22 -304
#define TV_D23 -303
#define TV_D24 -302
#define TV_D3D -301
#define TV_D3C -300
#define TV_D3B -299
#define TV_D3A -298
#define TV_D30 -297
#define TV_D31 -296
#define TV_D32 -295
#define TV_D33 -294
#define TV_D34 -293
#define TV_D4D -292
#define TV_D4C -291
#define TV_D4B -290
#define TV_D4A -289
#define TV_D40 -288
#define TV_D41 -287
#define TV_D42 -286
#define TV_D43 -285
#define TV_D44 -284
#define TV_CDD -283
#define TV_CDC -282
#define TV_CDB -281
#define TV_CDA -280
#define TV_CD0 -279
#define TV_CD1 -278
#define TV_CD2 -277
#define TV_CD3 -276
#define TV_CD4 -275
#define TV_CCD -274
#define TV_CCC -273
#define TV_CCB -272
#define TV_CCA -271
#define TV_CC0 -270
#define TV_CC1 -269
#define TV_CC2 -268
#define TV_CC3 -267
#define TV_CC4 -266
#define TV_CBD -265
#define TV_CBC -264
#define TV_CBB -263
#define TV_CBA -262
#define TV_CB0 -261
#define TV_CB1 -260
#define TV_CB2 -259
#define TV_CB3 -258
#define TV_CB4 -257
#define TV_CAD -256
#define TV_CAC -255
#define TV_CAB -254
#define TV_CAA -253
#define TV_CA0 -252
#define TV_CA1 -251
#define TV_CA2 -250
#define TV_CA3 -249
#define TV_CA4 -248
#define TV_C0D -247
#define TV_C0C -246
#define TV_C0B -245
#define TV_C0A -244
#define TV_C00 -243
#define TV_C01 -242
#define TV_C02 -241
#define TV_C03 -240
#define TV_C04 -239
#define TV_C1D -238
#define TV_C1C -237
#define TV_C1B -236
#define TV_C1A -235
#define TV_C10 -234
#define TV_C11 -233
#define TV_C12 -232
#define TV_C13 -231
#define TV_C14 -230
#define TV_C2D -229
#define TV_C2C -228
#define TV_C2B -227
#define TV_C2A -226
#define TV_C20 -225
#define TV_C21 -224
#define TV_C22 -223
#define TV_C23 -222
#define TV_C24 -221
#define TV_C3D -220
#define TV_C3C -219
#define TV_C3B -218
#define TV_C3A -217
#define TV_C30 -216
#define TV_C31 -215
#define TV_C32 -214
#define TV_C33 -213
#define TV_C34 -212
#define TV_C4D -211
#define TV_C4C -210
#define TV_C4B -209
#define TV_C4A -208
#define TV_C40 -207
#define TV_C41 -206
#define TV_C42 -205
#define TV_C43 -204
#define TV_C44 -203
#define TV_BDD -202
#define TV_BDC -201
#define TV_BDB -200
#define TV_BDA -199
#define TV_BD0 -198
#define TV_BD1 -197
#define TV_BD2 -196
#define TV_BD3 -195
#define TV_BD4 -194
#define TV_BCD -193
#define TV_BCC -192
#define TV_BCB -191
#define TV_BCA -190
#define TV_BC0 -189
#define TV_BC1 -188
#define TV_BC2 -187
#define TV_BC3 -186
#define TV_BC4 -185
#define TV_BBD -184
#define TV_BBC -183
#define TV_BBB -182
#define TV_BBA -181
#define TV_BB0 -180
#define TV_BB1 -179
#define TV_BB2 -178
#define TV_BB3 -177
#define TV_BB4 -176
#define TV_BAD -175
#define TV_BAC -174
#define TV_BAB -173
#define TV_BAA -172
#define TV_BA0 -171
#define TV_BA1 -170
#define TV_BA2 -169
#define TV_BA3 -168
#define TV_BA4 -167
#define TV_B0D -166
#define TV_B0C -165
#define TV_B0B -164
#define TV_B0A -163
#define TV_B00 -162
#define TV_B01 -161
#define TV_B02 -160
#define TV_B03 -159
#define TV_B04 -158
#define TV_B1D -157
#define TV_B1C -156
#define TV_B1B -155
#define TV_B1A -154
#define TV_B10 -153
#define TV_B11 -152
#define TV_B12 -151
#define TV_B13 -150
#define TV_B14 -149
#define TV_B2D -148
#define TV_B2C -147
#define TV_B2B -146
#define TV_B2A -145
#define TV_B20 -144
#define TV_B21 -143
#define TV_B22 -142
#define TV_B23 -141
#define TV_B24 -140
#define TV_B3D -139
#define TV_B3C -138
#define TV_B3B -137
#define TV_B3A -136
#define TV_B30 -135
#define TV_B31 -134
#define TV_B32 -133
#define TV_B33 -132
#define TV_B34 -131
#define TV_B4D -130
#define TV_B4C -129
#define TV_B4B -128
#define TV_B4A -127
#define TV_B40 -126
#define TV_B41 -125
#define TV_B42 -124
#define TV_B43 -123
#define TV_B44 -122
#define TV_ADD -121
#define TV_ADC -120
#define TV_ADB -119
#define TV_ADA -118
#define TV_AD0 -117
#define TV_AD1 -116
#define TV_AD2 -115
#define TV_AD3 -114
#define TV_AD4 -113
#define TV_ACD -112
#define TV_ACC -111
#define TV_ACB -110
#define TV_ACA -109
#define TV_AC0 -108
#define TV_AC1 -107
#define TV_AC2 -106
#define TV_AC3 -105
#define TV_AC4 -104
#define TV_ABD -103
#define TV_ABC -102
#define TV_ABB -101
#define TV_ABA -100
#define TV_AB0 -99
#define TV_AB1 -98
#define TV_AB2 -97
#define TV_AB3 -96
#define TV_AB4 -95
#define TV_AAD -94
#define TV_AAC -93
#define TV_AAB -92
#define TV_AAA -91
#define TV_AA0 -90
#define TV_AA1 -89
#define TV_AA2 -88
#define TV_AA3 -87
#define TV_AA4 -86
#define TV_A0D -85
#define TV_A0C -84
#define TV_A0B -83
#define TV_A0A -82
#define TV_A00 -81
#define TV_A01 -80
#define TV_A02 -79
#define TV_A03 -78
#define TV_A04 -77
#define TV_A1D -76
#define TV_A1C -75
#define TV_A1B -74
#define TV_A1A -73
#define TV_A10 -72
#define TV_A11 -71
#define TV_A12 -70
#define TV_A13 -69
#define TV_A14 -68
#define TV_A2D -67
#define TV_A2C -66
#define TV_A2B -65
#define TV_A2A -64
#define TV_A20 -63
#define TV_A21 -62
#define TV_A22 -61
#define TV_A23 -60
#define TV_A24 -59
#define TV_A3D -58
#define TV_A3C -57
#define TV_A3B -56
#define TV_A3A -55
#define TV_A30 -54
#define TV_A31 -53
#define TV_A32 -52
#define TV_A33 -51
#define TV_A34 -50
#define TV_A4D -49
#define TV_A4C -48
#define TV_A4B -47
#define TV_A4A -46
#define TV_A40 -45
#define TV_A41 -44
#define TV_A42 -43
#define TV_A43 -42
#define TV_A44 -41
#define TV_0DD -40
#define TV_0DC -39
#define TV_0DB -38
#define TV_0DA -37
#define TV_0D0 -36
#define TV_0D1 -35
#define TV_0D2 -34
#define TV_0D3 -33
#define TV_0D4 -32
#define TV_0CD -31
#define TV_0CC -30
#define TV_0CB -29
#define TV_0CA -28
#define TV_0C0 -27
#define TV_0C1 -26
#define TV_0C2 -25
#define TV_0C3 -24
#define TV_0C4 -23
#define TV_0BD -22
#define TV_0BC -21
#define TV_0BB -20
#define TV_0BA -19
#define TV_0B0 -18
#define TV_0B1 -17
#define TV_0B2 -16
#define TV_0B3 -15
#define TV_0B4 -14
#define TV_0AD -13
#define TV_0AC -12
#define TV_0AB -11
#define TV_0AA -10
#define TV_0A0 -9
#define TV_0A1 -8
#define TV_0A2 -7
#define TV_0A3 -6
#define TV_0A4 -5
#define TV_00D -4
#define TV_00C -3
#define TV_00B -2
#define TV_00A -1
#define TV_000 0
#define TV_001 1
#define TV_002 2
#define TV_003 3
#define TV_004 4
#define TV_01D 5
#define TV_01C 6
#define TV_01B 7
#define TV_01A 8
#define TV_010 9
#define TV_011 10
#define TV_012 11
#define TV_013 12
#define TV_014 13
#define TV_02D 14
#define TV_02C 15
#define TV_02B 16
#define TV_02A 17
#define TV_020 18
#define TV_021 19
#define TV_022 20
#define TV_023 21
#define TV_024 22
#define TV_03D 23
#define TV_03C 24
#define TV_03B 25
#define TV_03A 26
#define TV_030 27
#define TV_031 28
#define TV_032 29
#define TV_033 30
#define TV_034 31
#define TV_04D 32
#define TV_04C 33
#define TV_04B 34
#define TV_04A 35
#define TV_040 36
#define TV_041 37
#define TV_042 38
#define TV_043 39
#define TV_044 40
#define TV_1DD 41
#define TV_1DC 42
#define TV_1DB 43
#define TV_1DA 44
#define TV_1D0 45
#define TV_1D1 46
#define TV_1D2 47
#define TV_1D3 48
#define TV_1D4 49
#define TV_1CD 50
#define TV_1CC 51
#define TV_1CB 52
#define TV_1CA 53
#define TV_1C0 54
#define TV_1C1 55
#define TV_1C2 56
#define TV_1C3 57
#define TV_1C4 58
#define TV_1BD 59
#define TV_1BC 60
#define TV_1BB 61
#define TV_1BA 62
#define TV_1B0 63
#define TV_1B1 64
#define TV_1B2 65
#define TV_1B3 66
#define TV_1B4 67
#define TV_1AD 68
#define TV_1AC 69
#define TV_1AB 70
#define TV_1AA 71
#define TV_1A0 72
#define TV_1A1 73
#define TV_1A2 74
#define TV_1A3 75
#define TV_1A4 76
#define TV_10D 77
#define TV_10C 78
#define TV_10B 79
#define TV_10A 80
#define TV_100 81
#define TV_101 82
#define TV_102 83
#define TV_103 84
#define TV_104 85
#define TV_11D 86
#define TV_11C 87
#define TV_11B 88
#define TV_11A 89
#define TV_110 90
#define TV_111 91
#define TV_112 92
#define TV_113 93
#define TV_114 94
#define TV_12D 95
#define TV_12C 96
#define TV_12B 97
#define TV_12A 98
#define TV_120 99
#define TV_121 100
#define TV_122 101
#define TV_123 102
#define TV_124 103
#define TV_13D 104
#define TV_13C 105
#define TV_13B 106
#define TV_13A 107
#define TV_130 108
#define TV_131 109
#define TV_132 110
#define TV_133 111
#define TV_134 112
#define TV_14D 113
#define TV_14C 114
#define TV_14B 115
#define TV_14A 116
#define TV_140 117
#define TV_141 118
#define TV_142 119
#define TV_143 120
#define TV_144 121
#define TV_2DD 122
#define TV_2DC 123
#define TV_2DB 124
#define TV_2DA 125
#define TV_2D0 126
#define TV_2D1 127
#define TV_2D2 128
#define TV_2D3 129
#define TV_2D4 130
#define TV_2CD 131
#define TV_2CC 132
#define TV_2CB 133
#define TV_2CA 134
#define TV_2C0 135
#define TV_2C1 136
#define TV_2C2 137
#define TV_2C3 138
#define TV_2C4 139
#define TV_2BD 140
#define TV_2BC 141
#define TV_2BB 142
#define TV_2BA 143
#define TV_2B0 144
#define TV_2B1 145
#define TV_2B2 146
#define TV_2B3 147
#define TV_2B4 148
#define TV_2AD 149
#define TV_2AC 150
#define TV_2AB 151
#define TV_2AA 152
#define TV_2A0 153
#define TV_2A1 154
#define TV_2A2 155
#define TV_2A3 156
#define TV_2A4 157
#define TV_20D 158
#define TV_20C 159
#define TV_20B 160
#define TV_20A 161
#define TV_200 162
#define TV_201 163
#define TV_202 164
#define TV_203 165
#define TV_204 166
#define TV_21D 167
#define TV_21C 168
#define TV_21B 169
#define TV_21A 170
#define TV_210 171
#define TV_211 172
#define TV_212 173
#define TV_213 174
#define TV_214 175
#define TV_22D 176
#define TV_22C 177
#define TV_22B 178
#define TV_22A 179
#define TV_220 180
#define TV_221 181
#define TV_222 182
#define TV_223 183
#define TV_224 184
#define TV_23D 185
#define TV_23C 186
#define TV_23B 187
#define TV_23A 188
#define TV_230 189
#define TV_231 190
#define TV_232 191
#define TV_233 192
#define TV_234 193
#define TV_24D 194
#define TV_24C 195
#define TV_24B 196
#define TV_24A 197
#define TV_240 198
#define TV_241 199
#define TV_242 200
#define TV_243 201
#define TV_244 202
#define TV_3DD 203
#define TV_3DC 204
#define TV_3DB 205
#define TV_3DA 206
#define TV_3D0 207
#define TV_3D1 208
#define TV_3D2 209
#define TV_3D3 210
#define TV_3D4 211
#define TV_3CD 212
#define TV_3CC 213
#define TV_3CB 214
#define TV_3CA 215
#define TV_3C0 216
#define TV_3C1 217
#define TV_3C2 218
#define TV_3C3 219
#define TV_3C4 220
#define TV_3BD 221
#define TV_3BC 222
#define TV_3BB 223
#define TV_3BA 224
#define TV_3B0 225
#define TV_3B1 226
#define TV_3B2 227
#define TV_3B3 228
#define TV_3B4 229
#define TV_3AD 230
#define TV_3AC 231
#define TV_3AB 232
#define TV_3AA 233
#define TV_3A0 234
#define TV_3A1 235
#define TV_3A2 236
#define TV_3A3 237
#define TV_3A4 238
#define TV_30D 239
#define TV_30C 240
#define TV_30B 241
#define TV_30A 242
#define TV_300 243
#define TV_301 244
#define TV_302 245
#define TV_303 246
#define TV_304 247
#define TV_31D 248
#define TV_31C 249
#define TV_31B 250
#define TV_31A 251
#define TV_310 252
#define TV_311 253
#define TV_312 254
#define TV_313 255
#define TV_314 256
#define TV_32D 257
#define TV_32C 258
#define TV_32B 259
#define TV_32A 260
#define TV_320 261
#define TV_321 262
#define TV_322 263
#define TV_323 264
#define TV_324 265
#define TV_33D 266
#define TV_33C 267
#define TV_33B 268
#define TV_33A 269
#define TV_330 270
#define TV_331 271
#define TV_332 272
#define TV_333 273
#define TV_334 274
#define TV_34D 275
#define TV_34C 276
#define TV_34B 277
#define TV_34A 278
#define TV_340 279
#define TV_341 280
#define TV_342 281
#define TV_343 282
#define TV_344 283
#define TV_4DD 284
#define TV_4DC 285
#define TV_4DB 286
#define TV_4DA 287
#define TV_4D0 288
#define TV_4D1 289
#define TV_4D2 290
#define TV_4D3 291
#define TV_4D4 292
#define TV_4CD 293
#define TV_4CC 294
#define TV_4CB 295
#define TV_4CA 296
#define TV_4C0 297
#define TV_4C1 298
#define TV_4C2 299
#define TV_4C3 300
#define TV_4C4 301
#define TV_4BD 302
#define TV_4BC 303
#define TV_4BB 304
#define TV_4BA 305
#define TV_4B0 306
#define TV_4B1 307
#define TV_4B2 308
#define TV_4B3 309
#define TV_4B4 310
#define TV_4AD 311
#define TV_4AC 312
#define TV_4AB 313
#define TV_4AA 314
#define TV_4A0 315
#define TV_4A1 316
#define TV_4A2 317
#define TV_4A3 318
#define TV_4A4 319
#define TV_40D 320
#define TV_40C 321
#define TV_40B 322
#define TV_40A 323
#define TV_400 324
#define TV_401 325
#define TV_402 326
#define TV_403 327
#define TV_404 328
#define TV_41D 329
#define TV_41C 330
#define TV_41B 331
#define TV_41A 332
#define TV_410 333
#define TV_411 334
#define TV_412 335
#define TV_413 336
#define TV_414 337
#define TV_42D 338
#define TV_42C 339
#define TV_42B 340
#define TV_42A 341
#define TV_420 342
#define TV_421 343
#define TV_422 344
#define TV_423 345
#define TV_424 346
#define TV_43D 347
#define TV_43C 348
#define TV_43B 349
#define TV_43A 350
#define TV_430 351
#define TV_431 352
#define TV_432 353
#define TV_433 354
#define TV_434 355
#define TV_44D 356
#define TV_44C 357
#define TV_44B 358
#define TV_44A 359
#define TV_440 360
#define TV_441 361
#define TV_442 362
#define TV_443 363
#define TV_444 364

#endif
