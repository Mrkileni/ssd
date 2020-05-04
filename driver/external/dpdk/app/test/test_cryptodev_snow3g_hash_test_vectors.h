/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2016 Intel Corporation. All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *	 * Redistributions of source code must retain the above copyright
 *	   notice, this list of conditions and the following disclaimer.
 *	 * Redistributions in binary form must reproduce the above copyright
 *	   notice, this list of conditions and the following disclaimer in
 *	   the documentation and/or other materials provided with the
 *	   distribution.
 *	 * Neither the name of Intel Corporation nor the names of its
 *	   contributors may be used to endorse or promote products derived
 *	   from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TEST_CRYPTODEV_SNOW3G_HASH_TEST_VECTORS_H_
#define TEST_CRYPTODEV_SNOW3G_HASH_TEST_VECTORS_H_

struct snow3g_hash_test_data {
	struct {
		uint8_t data[64];
		unsigned len;
	} key;

	struct {
		uint8_t data[64];
		unsigned len;
	} aad;

	struct {
		uint8_t data[2056];
		unsigned len; /* length must be in Bits */
	} plaintext;

	struct {
		unsigned len;
	} validAuthLenInBits;

	struct {
		unsigned len;
	} validAuthOffsetLenInBits;

	struct {
		uint8_t data[64];
		unsigned len;
	} digest;
};

struct snow3g_hash_test_data snow3g_hash_test_case_1 = {
	.key = {
		.data = {
			0xC7, 0x36, 0xC6, 0xAA, 0xB2, 0x2B, 0xFF, 0xF9,
			0x1E, 0x26, 0x98, 0xD2, 0xE2, 0x2A, 0xD5, 0x7E
		},
	.len = 16
	},
	.aad = {
		.data = {
			0x14, 0x79, 0x3E, 0x41, 0x03, 0x97, 0xE8, 0xFD,
			0x94, 0x79, 0x3E, 0x41, 0x03, 0x97, 0x68, 0xFD
		},
		.len = 16
	},
	.plaintext = {
		.data = {
			0xD0, 0xA7, 0xD4, 0x63, 0xDF, 0x9F, 0xB2, 0xB2,
			0x78, 0x83, 0x3F, 0xA0, 0x2E, 0x23, 0x5A, 0xA1,
			0x72, 0xBD, 0x97, 0x0C, 0x14, 0x73, 0xE1, 0x29,
			0x07, 0xFB, 0x64, 0x8B, 0x65, 0x99, 0xAA, 0xA0,
			0xB2, 0x4A, 0x03, 0x86, 0x65, 0x42, 0x2B, 0x20,
			0xA4, 0x99, 0x27, 0x6A, 0x50, 0x42, 0x70, 0x09
		},
		.len = 384
	},
	.validAuthLenInBits = {
		.len = 384
		},
	.validAuthOffsetLenInBits = {
		.len = 128
	},
	.digest = {
		.data = {0x38, 0xB5, 0x54, 0xC0 },
		.len  = 4
	}
};

struct snow3g_hash_test_data snow3g_hash_test_case_2 = {
	.key = {
		.data = {
			0xF4, 0xEB, 0xEC, 0x69, 0xE7, 0x3E, 0xAF, 0x2E,
			0xB2, 0xCF, 0x6A, 0xF4, 0xB3, 0x12, 0x0F, 0xFD
		},
	.len = 16
	},
	.aad = {
		.data = {
			0x29, 0x6F, 0x39, 0x3C, 0x6B, 0x22, 0x77, 0x37,
			0xA9, 0x6F, 0x39, 0x3C, 0x6B, 0x22, 0xF7, 0x37
		},
		.len = 16
	},
	.plaintext = {
		.data = {
			0x10, 0xBF, 0xFF, 0x83, 0x9E, 0x0C, 0x71, 0x65,
			0x8D, 0xBB, 0x2D, 0x17, 0x07, 0xE1, 0x45, 0x72,
			0x4F, 0x41, 0xC1, 0x6F, 0x48, 0xBF, 0x40, 0x3C,
			0x3B, 0x18, 0xE3, 0x8F, 0xD5, 0xD1, 0x66, 0x3B,
			0x6F, 0x6D, 0x90, 0x01, 0x93, 0xE3, 0xCE, 0xA8,
			0xBB, 0x4F, 0x1B, 0x4F, 0x5B, 0xE8, 0x22, 0x03,
			0x22, 0x32, 0xA7, 0x8D, 0x7D, 0x75, 0x23, 0x8D,
			0x5E, 0x6D, 0xAE, 0xCD, 0x3B, 0x43, 0x22, 0xCF,
			0x59, 0xBC, 0x7E, 0xA8, 0x4A, 0xB1, 0x88, 0x11,
			0xB5, 0xBF, 0xB7, 0xBC, 0x55, 0x3F, 0x4F, 0xE4,
			0x44, 0x78, 0xCE, 0x28, 0x7A, 0x14, 0x87, 0x99,
			0x90, 0xD1, 0x8D, 0x12, 0xCA, 0x79, 0xD2, 0xC8,
			0x55, 0x14, 0x90, 0x21, 0xCD, 0x5C, 0xE8, 0xCA,
			0x03, 0x71, 0xCA, 0x04, 0xFC, 0xCE, 0x14, 0x3E,
			0x3D, 0x7C, 0xFE, 0xE9, 0x45, 0x85, 0xB5, 0x88,
			0x5C, 0xAC, 0x46, 0x06, 0x8B
		},
		.len = 1000
	},
	.validAuthLenInBits = {
		.len = 1000
	},
	.validAuthOffsetLenInBits = {
		.len = 128
	},
	.digest = {
		.data = {0x06, 0x17, 0x45, 0xAE},
		.len  = 4
	}
};

struct snow3g_hash_test_data snow3g_hash_test_case_3 = {
	.key = {
		.data = {
			0xB3, 0x12, 0x0F, 0xFD, 0xB2, 0xCF, 0x6A, 0xF4,
			0xE7, 0x3E, 0xAF, 0x2E, 0xF4, 0xEB, 0xEC, 0x69
		},
	.len = 16
	},
	.aad = {
		.data = {
			0x29, 0x6F, 0x39, 0x3C, 0x6B, 0x22, 0x77, 0x37,
			0xA9, 0x6F, 0x39, 0x3C, 0x6B, 0x22, 0xF7, 0x37
		},
	.len = 16
	},
	.plaintext = {
		.data = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
			0xE0, 0x95, 0x80, 0x45, 0xF3, 0xA0, 0xBB, 0xA4,
			0xE3, 0x96, 0x83, 0x46, 0xF0, 0xA3, 0xB8, 0xA7,
			0xC0, 0x2A, 0x01, 0x8A, 0xE6, 0x40, 0x76, 0x52,
			0x26, 0xB9, 0x87, 0xC9, 0x13, 0xE6, 0xCB, 0xF0,
			0x83, 0x57, 0x00, 0x16, 0xCF, 0x83, 0xEF, 0xBC,
			0x61, 0xC0, 0x82, 0x51, 0x3E, 0x21, 0x56, 0x1A,
			0x42, 0x7C, 0x00, 0x9D, 0x28, 0xC2, 0x98, 0xEF,
			0xAC, 0xE7, 0x8E, 0xD6, 0xD5, 0x6C, 0x2D, 0x45,
			0x05, 0xAD, 0x03, 0x2E, 0x9C, 0x04, 0xDC, 0x60,
			0xE7, 0x3A, 0x81, 0x69, 0x6D, 0xA6, 0x65, 0xC6,
			0xC4, 0x86, 0x03, 0xA5, 0x7B, 0x45, 0xAB, 0x33,
			0x22, 0x15, 0x85, 0xE6, 0x8E, 0xE3, 0x16, 0x91,
			0x87, 0xFB, 0x02, 0x39, 0x52, 0x86, 0x32, 0xDD,
			0x65, 0x6C, 0x80, 0x7E, 0xA3, 0x24, 0x8B, 0x7B,
			0x46, 0xD0, 0x02, 0xB2, 0xB5, 0xC7, 0x45, 0x8E,
			0xB8, 0x5B, 0x9C, 0xE9, 0x58, 0x79, 0xE0, 0x34,
			0x08, 0x59, 0x05, 0x5E, 0x3B, 0x0A, 0xBB, 0xC3,
			0xEA, 0xCE, 0x87, 0x19, 0xCA, 0xA8, 0x02, 0x65,
			0xC9, 0x72, 0x05, 0xD5, 0xDC, 0x4B, 0xCC, 0x90,
			0x2F, 0xE1, 0x83, 0x96, 0x29, 0xED, 0x71, 0x32,
			0x8A, 0x0F, 0x04, 0x49, 0xF5, 0x88, 0x55, 0x7E,
			0x68, 0x98, 0x86, 0x0E, 0x04, 0x2A, 0xEC, 0xD8,
			0x4B, 0x24, 0x04, 0xC2, 0x12, 0xC9, 0x22, 0x2D,
			0xA5, 0xBF, 0x8A, 0x89, 0xEF, 0x67, 0x97, 0x87,
			0x0C, 0xF5, 0x07, 0x71, 0xA6, 0x0F, 0x66, 0xA2,
			0xEE, 0x62, 0x85, 0x36, 0x57, 0xAD, 0xDF, 0x04,
			0xCD, 0xDE, 0x07, 0xFA, 0x41, 0x4E, 0x11, 0xF1,
			0x2B, 0x4D, 0x81, 0xB9, 0xB4, 0xE8, 0xAC, 0x53,
			0x8E, 0xA3, 0x06, 0x66, 0x68, 0x8D, 0x88, 0x1F,
			0x6C, 0x34, 0x84, 0x21, 0x99, 0x2F, 0x31, 0xB9,
			0x4F, 0x88, 0x06, 0xED, 0x8F, 0xCC, 0xFF, 0x4C,
			0x91, 0x23, 0xB8, 0x96, 0x42, 0x52, 0x7A, 0xD6,
			0x13, 0xB1, 0x09, 0xBF, 0x75, 0x16, 0x74, 0x85,
			0xF1, 0x26, 0x8B, 0xF8, 0x84, 0xB4, 0xCD, 0x23,
			0xD2, 0x9A, 0x09, 0x34, 0x92, 0x57, 0x03, 0xD6,
			0x34, 0x09, 0x8F, 0x77, 0x67, 0xF1, 0xBE, 0x74,
			0x91, 0xE7, 0x08, 0xA8, 0xBB, 0x94, 0x9A, 0x38,
			0x73, 0x70, 0x8A, 0xEF, 0x4A, 0x36, 0x23, 0x9E,
			0x50, 0xCC, 0x08, 0x23, 0x5C, 0xD5, 0xED, 0x6B,
			0xBE, 0x57, 0x86, 0x68, 0xA1, 0x7B, 0x58, 0xC1,
			0x17, 0x1D, 0x0B, 0x90, 0xE8, 0x13, 0xA9, 0xE4,
			0xF5, 0x8A, 0x89, 0xD7, 0x19, 0xB1, 0x10, 0x42,
			0xD6, 0x36, 0x0B, 0x1B, 0x0F, 0x52, 0xDE, 0xB7,
			0x30, 0xA5, 0x8D, 0x58, 0xFA, 0xF4, 0x63, 0x15,
			0x95, 0x4B, 0x0A, 0x87, 0x26, 0x91, 0x47, 0x59,
			0x77, 0xDC, 0x88, 0xC0, 0xD7, 0x33, 0xFE, 0xFF,
			0x54, 0x60, 0x0A, 0x0C, 0xC1, 0xD0, 0x30, 0x0A,
			0xAA, 0xEB, 0x94, 0x57, 0x2C, 0x6E, 0x95, 0xB0,
			0x1A, 0xE9, 0x0D, 0xE0, 0x4F, 0x1D, 0xCE, 0x47,
			0xF8, 0x7E, 0x8F, 0xA7, 0xBE, 0xBF, 0x77, 0xE1,
			0xDB, 0xC2, 0x0D, 0x6B, 0xA8, 0x5C, 0xB9, 0x14,
			0x3D, 0x51, 0x8B, 0x28, 0x5D, 0xFA, 0x04, 0xB6,
			0x98, 0xBF, 0x0C, 0xF7, 0x81, 0x9F, 0x20, 0xFA,
			0x7A, 0x28, 0x8E, 0xB0, 0x70, 0x3D, 0x99, 0x5C,
			0x59, 0x94, 0x0C, 0x7C, 0x66, 0xDE, 0x57, 0xA9,
			0xB7, 0x0F, 0x82, 0x37, 0x9B, 0x70, 0xE2, 0x03,
			0x1E, 0x45, 0x0F, 0xCF, 0xD2, 0x18, 0x13, 0x26,
			0xFC, 0xD2, 0x8D, 0x88, 0x23, 0xBA, 0xAA, 0x80,
			0xDF, 0x6E, 0x0F, 0x44, 0x35, 0x59, 0x64, 0x75,
			0x39, 0xFD, 0x89, 0x07, 0xC0, 0xFF, 0xD9, 0xD7,
			0x9C, 0x13, 0x0E, 0xD8, 0x1C, 0x9A, 0xFD, 0x9B,
			0x7E, 0x84, 0x8C, 0x9F, 0xED, 0x38, 0x44, 0x3D,
			0x5D, 0x38, 0x0E, 0x53, 0xFB, 0xDB, 0x8A, 0xC8,
			0xC3, 0xD3, 0xF0, 0x68, 0x76, 0x05, 0x4F, 0x12,
			0x24, 0x61, 0x10, 0x7D, 0xE9, 0x2F, 0xEA, 0x09,
			0xC6, 0xF6, 0x92, 0x3A, 0x18, 0x8D, 0x53, 0xAF,
			0xE5, 0x4A, 0x10, 0xF6, 0x0E, 0x6E, 0x9D, 0x5A,
			0x03, 0xD9, 0x96, 0xB5, 0xFB, 0xC8, 0x20, 0xF8,
			0xA6, 0x37, 0x11, 0x6A, 0x27, 0xAD, 0x04, 0xB4,
			0x44, 0xA0, 0x93, 0x2D, 0xD6, 0x0F, 0xBD, 0x12,
			0x67, 0x1C, 0x11, 0xE1, 0xC0, 0xEC, 0x73, 0xE7,
			0x89, 0x87, 0x9F, 0xAA, 0x3D, 0x42, 0xC6, 0x4D,
			0x20, 0xCD, 0x12, 0x52, 0x74, 0x2A, 0x37, 0x68,
			0xC2, 0x5A, 0x90, 0x15, 0x85, 0x88, 0x8E, 0xCE,
			0xE1, 0xE6, 0x12, 0xD9, 0x93, 0x6B, 0x40, 0x3B,
			0x07, 0x75, 0x94, 0x9A, 0x66, 0xCD, 0xFD, 0x99,
			0xA2, 0x9B, 0x13, 0x45, 0xBA, 0xA8, 0xD9, 0xD5,
			0x40, 0x0C, 0x91, 0x02, 0x4B, 0x0A, 0x60, 0x73,
			0x63, 0xB0, 0x13, 0xCE, 0x5D, 0xE9, 0xAE, 0x86,
			0x9D, 0x3B, 0x8D, 0x95, 0xB0, 0x57, 0x0B, 0x3C,
			0x2D, 0x39, 0x14, 0x22, 0xD3, 0x24, 0x50, 0xCB,
			0xCF, 0xAE, 0x96, 0x65, 0x22, 0x86, 0xE9, 0x6D,
			0xEC, 0x12, 0x14, 0xA9, 0x34, 0x65, 0x27, 0x98,
			0x0A, 0x81, 0x92, 0xEA, 0xC1, 0xC3, 0x9A, 0x3A,
			0xAF, 0x6F, 0x15, 0x35, 0x1D, 0xA6, 0xBE, 0x76,
			0x4D, 0xF8, 0x97, 0x72, 0xEC, 0x04, 0x07, 0xD0,
			0x6E, 0x44, 0x15, 0xBE, 0xFA, 0xE7, 0xC9, 0x25,
			0x80, 0xDF, 0x9B, 0xF5, 0x07, 0x49, 0x7C, 0x8F,
			0x29, 0x95, 0x16, 0x0D, 0x4E, 0x21, 0x8D, 0xAA,
			0xCB, 0x02, 0x94, 0x4A, 0xBF, 0x83, 0x34, 0x0C,
			0xE8, 0xBE, 0x16, 0x86, 0xA9, 0x60, 0xFA, 0xF9,
			0x0E, 0x2D, 0x90, 0xC5, 0x5C, 0xC6, 0x47, 0x5B,
			0xAB, 0xC3, 0x17, 0x1A, 0x80, 0xA3, 0x63, 0x17,
			0x49, 0x54, 0x95, 0x5D, 0x71, 0x01, 0xDA, 0xB1,
			0x6A, 0xE8, 0x17, 0x91, 0x67, 0xE2, 0x14, 0x44,
			0xB4, 0x43, 0xA9, 0xEA, 0xAA, 0x7C, 0x91, 0xDE,
			0x36, 0xD1, 0x18, 0xC3, 0x9D, 0x38, 0x9F, 0x8D,
			0xD4, 0x46, 0x9A, 0x84, 0x6C, 0x9A, 0x26, 0x2B,
			0xF7, 0xFA, 0x18, 0x48, 0x7A, 0x79, 0xE8, 0xDE,
			0x11, 0x69, 0x9E, 0x0B, 0x8F, 0xDF, 0x55, 0x7C,
			0xB4, 0x87, 0x19, 0xD4, 0x53, 0xBA, 0x71, 0x30,
			0x56, 0x10, 0x9B, 0x93, 0xA2, 0x18, 0xC8, 0x96,
			0x75, 0xAC, 0x19, 0x5F, 0xB4, 0xFB, 0x06, 0x63,
			0x9B, 0x37, 0x97, 0x14, 0x49, 0x55, 0xB3, 0xC9,
			0x32, 0x7D, 0x1A, 0xEC, 0x00, 0x3D, 0x42, 0xEC,
			0xD0, 0xEA, 0x98, 0xAB, 0xF1, 0x9F, 0xFB, 0x4A,
			0xF3, 0x56, 0x1A, 0x67, 0xE7, 0x7C, 0x35, 0xBF,
			0x15, 0xC5, 0x9C, 0x24, 0x12, 0xDA, 0x88, 0x1D,
			0xB0, 0x2B, 0x1B, 0xFB, 0xCE, 0xBF, 0xAC, 0x51,
			0x52, 0xBC, 0x99, 0xBC, 0x3F, 0x1D, 0x15, 0xF7,
			0x71, 0x00, 0x1B, 0x70, 0x29, 0xFE, 0xDB, 0x02,
			0x8F, 0x8B, 0x85, 0x2B, 0xC4, 0x40, 0x7E, 0xB8,
			0x3F, 0x89, 0x1C, 0x9C, 0xA7, 0x33, 0x25, 0x4F,
			0xDD, 0x1E, 0x9E, 0xDB, 0x56, 0x91, 0x9C, 0xE9,
			0xFE, 0xA2, 0x1C, 0x17, 0x40, 0x72, 0x52, 0x1C,
			0x18, 0x31, 0x9A, 0x54, 0xB5, 0xD4, 0xEF, 0xBE,
			0xBD, 0xDF, 0x1D, 0x8B, 0x69, 0xB1, 0xCB, 0xF2,
			0x5F, 0x48, 0x9F, 0xCC, 0x98, 0x13, 0x72, 0x54,
			0x7C, 0xF4, 0x1D, 0x00, 0x8E, 0xF0, 0xBC, 0xA1,
			0x92, 0x6F, 0x93, 0x4B, 0x73, 0x5E, 0x09, 0x0B,
			0x3B, 0x25, 0x1E, 0xB3, 0x3A, 0x36, 0xF8, 0x2E,
			0xD9, 0xB2, 0x9C, 0xF4, 0xCB, 0x94, 0x41, 0x88,
			0xFA, 0x0E, 0x1E, 0x38, 0xDD, 0x77, 0x8F, 0x7D,
			0x1C, 0x9D, 0x98, 0x7B, 0x28, 0xD1, 0x32, 0xDF,
			0xB9, 0x73, 0x1F, 0xA4, 0xF4, 0xB4, 0x16, 0x93,
			0x5B, 0xE4, 0x9D, 0xE3, 0x05, 0x16, 0xAF, 0x35,
			0x78, 0x58, 0x1F, 0x2F, 0x13, 0xF5, 0x61, 0xC0,
			0x66, 0x33, 0x61, 0x94, 0x1E, 0xAB, 0x24, 0x9A,
			0x4B, 0xC1, 0x23, 0xF8, 0xD1, 0x5C, 0xD7, 0x11,
			0xA9, 0x56, 0xA1, 0xBF, 0x20, 0xFE, 0x6E, 0xB7,
			0x8A, 0xEA, 0x23, 0x73, 0x36, 0x1D, 0xA0, 0x42,
			0x6C, 0x79, 0xA5, 0x30, 0xC3, 0xBB, 0x1D, 0xE0,
			0xC9, 0x97, 0x22, 0xEF, 0x1F, 0xDE, 0x39, 0xAC,
			0x2B, 0x00, 0xA0, 0xA8, 0xEE, 0x7C, 0x80, 0x0A,
			0x08, 0xBC, 0x22, 0x64, 0xF8, 0x9F, 0x4E, 0xFF,
			0xE6, 0x27, 0xAC, 0x2F, 0x05, 0x31, 0xFB, 0x55,
			0x4F, 0x6D, 0x21, 0xD7, 0x4C, 0x59, 0x0A, 0x70,
			0xAD, 0xFA, 0xA3, 0x90, 0xBD, 0xFB, 0xB3, 0xD6,
			0x8E, 0x46, 0x21, 0x5C, 0xAB, 0x18, 0x7D, 0x23,
			0x68, 0xD5, 0xA7, 0x1F, 0x5E, 0xBE, 0xC0, 0x81,
			0xCD, 0x3B, 0x20, 0xC0, 0x82, 0xDB, 0xE4, 0xCD,
			0x2F, 0xAC, 0xA2, 0x87, 0x73, 0x79, 0x5D, 0x6B,
			0x0C, 0x10, 0x20, 0x4B, 0x65, 0x9A, 0x93, 0x9E,
			0xF2, 0x9B, 0xBE, 0x10, 0x88, 0x24, 0x36, 0x24,
			0x42, 0x99, 0x27, 0xA7, 0xEB, 0x57, 0x6D, 0xD3,
			0xA0, 0x0E, 0xA5, 0xE0, 0x1A, 0xF5, 0xD4, 0x75,
			0x83, 0xB2, 0x27, 0x2C, 0x0C, 0x16, 0x1A, 0x80,
			0x65, 0x21, 0xA1, 0x6F, 0xF9, 0xB0, 0xA7, 0x22,
			0xC0, 0xCF, 0x26, 0xB0, 0x25, 0xD5, 0x83, 0x6E,
			0x22, 0x58, 0xA4, 0xF7, 0xD4, 0x77, 0x3A, 0xC8,
			0x01, 0xE4, 0x26, 0x3B, 0xC2, 0x94, 0xF4, 0x3D,
			0xEF, 0x7F, 0xA8, 0x70, 0x3F, 0x3A, 0x41, 0x97,
			0x46, 0x35, 0x25, 0x88, 0x76, 0x52, 0xB0, 0xB2,
			0xA4, 0xA2, 0xA7, 0xCF, 0x87, 0xF0, 0x09, 0x14,
			0x87, 0x1E, 0x25, 0x03, 0x91, 0x13, 0xC7, 0xE1,
			0x61, 0x8D, 0xA3, 0x40, 0x64, 0xB5, 0x7A, 0x43,
			0xC4, 0x63, 0x24, 0x9F, 0xB8, 0xD0, 0x5E, 0x0F,
			0x26, 0xF4, 0xA6, 0xD8, 0x49, 0x72, 0xE7, 0xA9,
			0x05, 0x48, 0x24, 0x14, 0x5F, 0x91, 0x29, 0x5C,
			0xDB, 0xE3, 0x9A, 0x6F, 0x92, 0x0F, 0xAC, 0xC6,
			0x59, 0x71, 0x2B, 0x46, 0xA5, 0x4B, 0xA2, 0x95,
			0xBB, 0xE6, 0xA9, 0x01, 0x54, 0xE9, 0x1B, 0x33,
			0x98, 0x5A, 0x2B, 0xCD, 0x42, 0x0A, 0xD5, 0xC6,
			0x7E, 0xC9, 0xAD, 0x8E, 0xB7, 0xAC, 0x68, 0x64,
			0xDB, 0x27, 0x2A, 0x51, 0x6B, 0xC9, 0x4C, 0x28,
			0x39, 0xB0, 0xA8, 0x16, 0x9A, 0x6B, 0xF5, 0x8E,
			0x1A, 0x0C, 0x2A, 0xDA, 0x8C, 0x88, 0x3B, 0x7B,
			0xF4, 0x97, 0xA4, 0x91, 0x71, 0x26, 0x8E, 0xD1,
			0x5D, 0xDD, 0x29, 0x69, 0x38, 0x4E, 0x7F, 0xF4,
			0xBF, 0x4A, 0xAB, 0x2E, 0xC9, 0xEC, 0xC6, 0x52,
			0x9C, 0xF6, 0x29, 0xE2, 0xDF, 0x0F, 0x08, 0xA7,
			0x7A, 0x65, 0xAF, 0xA1, 0x2A, 0xA9, 0xB5, 0x05,
			0xDF, 0x8B, 0x28, 0x7E, 0xF6, 0xCC, 0x91, 0x49,
			0x3D, 0x1C, 0xAA, 0x39, 0x07, 0x6E, 0x28, 0xEF,
			0x1E, 0xA0, 0x28, 0xF5, 0x11, 0x8D, 0xE6, 0x1A,
			0xE0, 0x2B, 0xB6, 0xAE, 0xFC, 0x33, 0x43, 0xA0,
			0x50, 0x29, 0x2F, 0x19, 0x9F, 0x40, 0x18, 0x57,
			0xB2, 0xBE, 0xAD, 0x5E, 0x6E, 0xE2, 0xA1, 0xF1,
			0x91, 0x02, 0x2F, 0x92, 0x78, 0x01, 0x6F, 0x04,
			0x77, 0x91, 0xA9, 0xD1, 0x8D, 0xA7, 0xD2, 0xA6,
			0xD2, 0x7F, 0x2E, 0x0E, 0x51, 0xC2, 0xF6, 0xEA,
			0x30, 0xE8, 0xAC, 0x49, 0xA0, 0x60, 0x4F, 0x4C,
			0x13, 0x54, 0x2E, 0x85, 0xB6, 0x83, 0x81, 0xB9,
			0xFD, 0xCF, 0xA0, 0xCE, 0x4B, 0x2D, 0x34, 0x13,
			0x54, 0x85, 0x2D, 0x36, 0x02, 0x45, 0xC5, 0x36,
			0xB6, 0x12, 0xAF, 0x71, 0xF3, 0xE7, 0x7C, 0x90,
			0x95, 0xAE, 0x2D, 0xBD, 0xE5, 0x04, 0xB2, 0x65,
			0x73, 0x3D, 0xAB, 0xFE, 0x10, 0xA2, 0x0F, 0xC7,
			0xD6, 0xD3, 0x2C, 0x21, 0xCC, 0xC7, 0x2B, 0x8B,
			0x34, 0x44, 0xAE, 0x66, 0x3D, 0x65, 0x92, 0x2D,
			0x17, 0xF8, 0x2C, 0xAA, 0x2B, 0x86, 0x5C, 0xD8,
			0x89, 0x13, 0xD2, 0x91, 0xA6, 0x58, 0x99, 0x02,
			0x6E, 0xA1, 0x32, 0x84, 0x39, 0x72, 0x3C, 0x19,
			0x8C, 0x36, 0xB0, 0xC3, 0xC8, 0xD0, 0x85, 0xBF,
			0xAF, 0x8A, 0x32, 0x0F, 0xDE, 0x33, 0x4B, 0x4A,
			0x49, 0x19, 0xB4, 0x4C, 0x2B, 0x95, 0xF6, 0xE8,
			0xEC, 0xF7, 0x33, 0x93, 0xF7, 0xF0, 0xD2, 0xA4,
			0x0E, 0x60, 0xB1, 0xD4, 0x06, 0x52, 0x6B, 0x02,
			0x2D, 0xDC, 0x33, 0x18, 0x10, 0xB1, 0xA5, 0xF7,
			0xC3, 0x47, 0xBD, 0x53, 0xED, 0x1F, 0x10, 0x5D,
			0x6A, 0x0D, 0x30, 0xAB, 0xA4, 0x77, 0xE1, 0x78,
			0x88, 0x9A, 0xB2, 0xEC, 0x55, 0xD5, 0x58, 0xDE,
			0xAB, 0x26, 0x30, 0x20, 0x43, 0x36, 0x96, 0x2B,
			0x4D, 0xB5, 0xB6, 0x63, 0xB6, 0x90, 0x2B, 0x89,
			0xE8, 0x5B, 0x31, 0xBC, 0x6A, 0xF5, 0x0F, 0xC5,
			0x0A, 0xCC, 0xB3, 0xFB, 0x9B, 0x57, 0xB6, 0x63,
			0x29, 0x70, 0x31, 0x37, 0x8D, 0xB4, 0x78, 0x96,
			0xD7, 0xFB, 0xAF, 0x6C, 0x60, 0x0A, 0xDD, 0x2C,
			0x67, 0xF9, 0x36, 0xDB, 0x03, 0x79, 0x86, 0xDB,
			0x85, 0x6E, 0xB4, 0x9C, 0xF2, 0xDB, 0x3F, 0x7D,
			0xA6, 0xD2, 0x36, 0x50, 0xE4, 0x38, 0xF1, 0x88,
			0x40, 0x41, 0xB0, 0x13, 0x11, 0x9E, 0x4C, 0x2A,
			0xE5, 0xAF, 0x37, 0xCC, 0xCD, 0xFB, 0x68, 0x66,
			0x07, 0x38, 0xB5, 0x8B, 0x3C, 0x59, 0xD1, 0xC0,
			0x24, 0x84, 0x37, 0x47, 0x2A, 0xBA, 0x1F, 0x35,
			0xCA, 0x1F, 0xB9, 0x0C, 0xD7, 0x14, 0xAA, 0x9F,
			0x63, 0x55, 0x34, 0xF4, 0x9E, 0x7C, 0x5B, 0xBA,
			0x81, 0xC2, 0xB6, 0xB3, 0x6F, 0xDE, 0xE2, 0x1C,
			0xA2, 0x7E, 0x34, 0x7F, 0x79, 0x3D, 0x2C, 0xE9,
			0x44, 0xED, 0xB2, 0x3C, 0x8C, 0x9B, 0x91, 0x4B,
			0xE1, 0x03, 0x35, 0xE3, 0x50, 0xFE, 0xB5, 0x07,
			0x03, 0x94, 0xB7, 0xA4, 0xA1, 0x5C, 0x0C, 0xA1,
			0x20, 0x28, 0x35, 0x68, 0xB7, 0xBF, 0xC2, 0x54,
			0xFE, 0x83, 0x8B, 0x13, 0x7A, 0x21, 0x47, 0xCE,
			0x7C, 0x11, 0x3A, 0x3A, 0x4D, 0x65, 0x49, 0x9D,
			0x9E, 0x86, 0xB8, 0x7D, 0xBC, 0xC7, 0xF0, 0x3B,
			0xBD, 0x3A, 0x3A, 0xB1, 0xAA, 0x24, 0x3E, 0xCE,
			0x5B, 0xA9, 0xBC, 0xF2, 0x5F, 0x82, 0x83, 0x6C,
			0xFE, 0x47, 0x3B, 0x2D, 0x83, 0xE7, 0xA7, 0x20,
			0x1C, 0xD0, 0xB9, 0x6A, 0x72, 0x45, 0x1E, 0x86,
			0x3F, 0x6C, 0x3B, 0xA6, 0x64, 0xA6, 0xD0, 0x73,
			0xD1, 0xF7, 0xB5, 0xED, 0x99, 0x08, 0x65, 0xD9,
			0x78, 0xBD, 0x38, 0x15, 0xD0, 0x60, 0x94, 0xFC,
			0x9A, 0x2A, 0xBA, 0x52, 0x21, 0xC2, 0x2D, 0x5A,
			0xB9, 0x96, 0x38, 0x9E, 0x37, 0x21, 0xE3, 0xAF,
			0x5F, 0x05, 0xBE, 0xDD, 0xC2, 0x87, 0x5E, 0x0D,
			0xFA, 0xEB, 0x39, 0x02, 0x1E, 0xE2, 0x7A, 0x41,
			0x18, 0x7C, 0xBB, 0x45, 0xEF, 0x40, 0xC3, 0xE7,
			0x3B, 0xC0, 0x39, 0x89, 0xF9, 0xA3, 0x0D, 0x12,
			0xC5, 0x4B, 0xA7, 0xD2, 0x14, 0x1D, 0xA8, 0xA8,
			0x75, 0x49, 0x3E, 0x65, 0x77, 0x6E, 0xF3, 0x5F,
			0x97, 0xDE, 0xBC, 0x22, 0x86, 0xCC, 0x4A, 0xF9,
			0xB4, 0x62, 0x3E, 0xEE, 0x90, 0x2F, 0x84, 0x0C,
			0x52, 0xF1, 0xB8, 0xAD, 0x65, 0x89, 0x39, 0xAE,
			0xF7, 0x1F, 0x3F, 0x72, 0xB9, 0xEC, 0x1D, 0xE2,
			0x15, 0x88, 0xBD, 0x35, 0x48, 0x4E, 0xA4, 0x44,
			0x36, 0x34, 0x3F, 0xF9, 0x5E, 0xAD, 0x6A, 0xB1,
			0xD8, 0xAF, 0xB1, 0xB2, 0xA3, 0x03, 0xDF, 0x1B,
			0x71, 0xE5, 0x3C, 0x4A, 0xEA, 0x6B, 0x2E, 0x3E,
			0x93, 0x72, 0xBE, 0x0D, 0x1B, 0xC9, 0x97, 0x98,
			0xB0, 0xCE, 0x3C, 0xC1, 0x0D, 0x2A, 0x59, 0x6D,
			0x56, 0x5D, 0xBA, 0x82, 0xF8, 0x8C, 0xE4, 0xCF,
			0xF3, 0xB3, 0x3D, 0x5D, 0x24, 0xE9, 0xC0, 0x83,
			0x11, 0x24, 0xBF, 0x1A, 0xD5, 0x4B, 0x79, 0x25,
			0x32, 0x98, 0x3D, 0xD6, 0xC3, 0xA8, 0xB7, 0xD0
		},
	.len = 16448
	},
	.validAuthLenInBits = {
		.len = 16448
	},
	.validAuthOffsetLenInBits = {
		.len = 128
	},
	.digest = {
		.data = {0x17, 0x9F, 0x2F, 0xA6},
		.len  = 4
	}
};

struct snow3g_hash_test_data snow3g_hash_test_case_4 = {
	.key = {
		.data = {
			0x2B, 0xD6, 0x45, 0x9F, 0x82, 0xC5, 0xB3, 0x00,
			0x95, 0x2C, 0x49, 0x10, 0x48, 0x81, 0xFF, 0x48
		},
	.len = 16
	},
	.aad = {
		.data = {
			0x38, 0xA6, 0xF0, 0x56, 0x05, 0xD2, 0xEC, 0x49,
			0x38, 0xA6, 0xF0, 0x56, 0x05, 0xD2, 0xEC, 0x49,
		},
		.len = 16
	},
	.plaintext = {
		.data = {
			0x6B, 0x22, 0x77, 0x37, 0x29, 0x6F, 0x39, 0x3C,
			0x80, 0x79, 0x35, 0x3E, 0xDC, 0x87, 0xE2, 0xE8,
			0x05, 0xD2, 0xEC, 0x49, 0xA4, 0xF2, 0xD8, 0xE0
		},
		.len = 189
	},
	.validAuthLenInBits = {
		.len = 189
		},
	.validAuthOffsetLenInBits = {
		.len = 128
	},
	.digest = {
		.data = {0x2B, 0xCE, 0x18, 0x20},
		.len  = 4
	}
};

struct snow3g_hash_test_data snow3g_hash_test_case_5 = {
	.key = {
		.data = {
			0xD4, 0x2F, 0x68, 0x24, 0x28, 0x20, 0x1C, 0xAF,
			0xCD, 0x9F, 0x97, 0x94, 0x5E, 0x6D, 0xE7, 0xB7
		},
		.len = 16
	},
	.aad = {
		.data = {
			0x3E, 0xDC, 0x87, 0xE2, 0xA4, 0xF2, 0xD8, 0xE2,
			0xBE, 0xDC, 0x87, 0xE2, 0xA4, 0xF2, 0x58, 0xE2
		},
		.len = 16
	},
	.plaintext = {
		.data = {
			0xB5, 0x92, 0x43, 0x84, 0x32, 0x8A, 0x4A, 0xE0,
			0x0B, 0x73, 0x71, 0x09, 0xF8, 0xB6, 0xC8, 0xDD,
			0x2B, 0x4D, 0xB6, 0x3D, 0xD5, 0x33, 0x98, 0x1C,
			0xEB, 0x19, 0xAA, 0xD5, 0x2A, 0x5B, 0x2B, 0xC0
		},
		.len = 254
	},
	.validAuthLenInBits = {
		.len = 254
		},
	.validAuthOffsetLenInBits = {
		.len = 128
	},
	.digest = {
		.data = {0xFC, 0x7B, 0x18, 0xBD},
		.len  = 4
	}
};

struct snow3g_hash_test_data snow3g_hash_test_case_6 = {
	.key = {
		.data = {
			0xFD, 0xB9, 0xCF, 0xDF, 0x28, 0x93, 0x6C, 0xC4,
			0x83, 0xA3, 0x18, 0x69, 0xD8, 0x1B, 0x8F, 0xAB
		},
		.len = 16
	},
	.aad = {
		.data = {
			0x36, 0xAF, 0x61, 0x44, 0x98, 0x38, 0xF0, 0x3A,
			0xB6, 0xAF, 0x61, 0x44, 0x98, 0x38, 0x70, 0x3A
		},
		.len = 16
	},
	.plaintext = {
		.data = {
			0x59, 0x32, 0xBC, 0x0A, 0xCE, 0x2B, 0x0A, 0xBA,
			0x33, 0xD8, 0xAC, 0x18, 0x8A, 0xC5, 0x4F, 0x34,
			0x6F, 0xAD, 0x10, 0xBF, 0x9D, 0xEE, 0x29, 0x20,
			0xB4, 0x3B, 0xD0, 0xC5, 0x3A, 0x91, 0x5C, 0xB7,
			0xDF, 0x6C, 0xAA, 0x72, 0x05, 0x3A, 0xBF, 0xF2
		},
		.len = 319
	},
	.validAuthLenInBits = {
		.len = 319
		},
	.validAuthOffsetLenInBits = {
		.len = 128
	},
	.digest = {
		.data = {0x02, 0xF1, 0xFA, 0xAF},
		.len  = 4
	}
};
#endif /* TEST_CRYPTODEV_SNOW3G_HASH_TEST_VECTORS_H_ */
