/*
 * FCML - Free Code Manipulation Library.
 * Copyright (C) 2010-2015 Slawomir Wojtasiak
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "modrm_encoder_t.h"

#include <fcml_env_int.h>
#include <fcml_modrm_encoder.h>
#include <fcml_errors.h>
#include <fcml_common.h>

fcml_bool fcml_tf_modrm_encoder_suite_init(void) {
	return FCML_TRUE;
}

fcml_bool fcml_tf_modrm_encoder_suite_cleanup(void) {
	return FCML_TRUE;
}

/* [EAX]*/
void fcml_tf_modrm_encoder_test_1(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EAX;
	modrm.address.effective_address.base.size = FCML_DS_32;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT_EQUAL( effective_address_size, FCML_EN_ASF_32 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* [RAX]*/
void fcml_tf_modrm_encoder_test_2(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_RAX;
	modrm.address.effective_address.base.size = FCML_DS_64;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT_EQUAL( effective_address_size, FCML_EN_ASF_64 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* [AX]*/
void fcml_tf_modrm_encoder_test_3(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_AX;
	modrm.address.effective_address.base.size = FCML_DS_16;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT_EQUAL( effective_address_size, FCML_EN_ASF_16 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}


/* SIB index [AX]*/
void fcml_tf_modrm_encoder_test_4(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_AX;
	modrm.address.effective_address.index.size = FCML_DS_16;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT_EQUAL( effective_address_size, FCML_EN_ASF_16 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* SIB index [EAX]*/
void fcml_tf_modrm_encoder_test_5(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EAX;
	modrm.address.effective_address.index.size = FCML_DS_32;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT_EQUAL( effective_address_size, FCML_EN_ASF_32 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* SIB index [RAX]*/
void fcml_tf_modrm_encoder_test_6(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_RAX;
	modrm.address.effective_address.index.size = FCML_DS_64;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT_EQUAL( effective_address_size, FCML_EN_ASF_64 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* displacement 8*/
void fcml_tf_modrm_encoder_test_7(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.displacement.size = FCML_DS_8;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT( effective_address_size & FCML_EN_ASF_16 );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_32 );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_64 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* displacement 16*/
void fcml_tf_modrm_encoder_test_8(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.displacement.size = FCML_DS_16;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT( effective_address_size & FCML_EN_ASF_16 );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_32 );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_64 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* displacement 64*/
void fcml_tf_modrm_encoder_test_9(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.displacement.size = FCML_DS_32;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT( effective_address_size & FCML_EN_ASF_16 );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_32 );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_64 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* SIB index [XMM]*/
void fcml_tf_modrm_encoder_test_10(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.index.type = FCML_REG_SIMD;
	modrm.address.effective_address.index.reg = FCML_REG_XMM1;
	modrm.address.effective_address.index.size = FCML_DS_128;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT( !(effective_address_size & FCML_EN_ASF_16 ) );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_32 );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_64 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* SIB index [YMM]*/
void fcml_tf_modrm_encoder_test_11(void) {

	fcml_flags effective_address_size;

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.index.type = FCML_REG_SIMD;
	modrm.address.effective_address.index.reg = FCML_REG_XMM1;
	modrm.address.effective_address.index.size = FCML_DS_256;

	fcml_ceh_error error = fcml_fn_modrm_calculate_effective_address_size( &modrm, &effective_address_size );

	STF_ASSERT( !(effective_address_size & FCML_EN_ASF_16) );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_32 );
	STF_ASSERT( effective_address_size & FCML_EN_ASF_64 );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

/* Encode disp16*/
void fcml_tf_modrm_encoder_test_12(void) {

	fcml_st_modrm modrm;

	/* As displacement.*/

	/* Exactly the same size.*/

	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.displacement.size = FCML_DS_16;
	modrm.address.effective_address.displacement.int16 = (fcml_int16_t)0xF2F1;
	modrm.address.address_form = FCML_AF_OFFSET;

	fcml_st_modrm_encoder_context context;
	context.op_mode = FCML_OM_16_BIT;
	context.effective_address_size = FCML_DS_16;

	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0xF2 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );

	/* 8 bit sign extended.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.effective_address.displacement.size = FCML_DS_8;
    modrm.address.effective_address.displacement.int8 = (fcml_int8_t)0xF1;
    modrm.address.effective_address.displacement.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0xFF );
    STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );

    /* 32 bits - to 16 bits.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.effective_address.displacement.size = FCML_DS_32;
    modrm.address.effective_address.displacement.int32 = 0xFFFFFFF1;
    modrm.address.effective_address.displacement.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0xFF );
    STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );

    /* 64 bits - to 16 bits.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.effective_address.displacement.size = FCML_DS_64;
    modrm.address.effective_address.displacement.int64 = 0xFFFFFFFFFFFFFFF1ULL;
    modrm.address.effective_address.displacement.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0xFF );
    STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );

    /* 64 bits - to 16 bits, overflow.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.effective_address.displacement.size = FCML_DS_64;
    modrm.address.effective_address.displacement.int64 = 0x1FFFFFFFFFFFFFF1ULL;
    modrm.address.effective_address.displacement.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_VALUE_OUT_OF_RANGE );

    /* 32 bits - to 16 bits, overflow.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.effective_address.displacement.size = FCML_DS_64;
    modrm.address.effective_address.displacement.int64 = 0x1FFFFFF1ULL;
    modrm.address.effective_address.displacement.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_VALUE_OUT_OF_RANGE );
}

/* Encode disp8*/
void fcml_tf_modrm_encoder_test_13(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

	modrm.address.effective_address.displacement.size = FCML_DS_8;
	modrm.address.effective_address.displacement.int8 = (fcml_int8_t)0xF1;
	modrm.address.effective_address.displacement.is_signed = FCML_FALSE;
	modrm.address.address_form = FCML_AF_OFFSET;

	fcml_st_modrm_encoder_context context;
	context.op_mode = FCML_OM_16_BIT;
	context.effective_address_size = FCML_DS_16;

	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );
}

/* Encode disp16*/
void fcml_tf_modrm_encoder_test_14(void) {

    fcml_st_modrm modrm;

    /* As displacement.*/

    /* Exactly the same size.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.offset.size = FCML_DS_16;
    modrm.address.offset.off16 = (fcml_int16_t)0xF2F1;
    modrm.address.address_form = FCML_AF_OFFSET;

    fcml_st_modrm_encoder_context context;
    context.op_mode = FCML_OM_16_BIT;
    context.effective_address_size = FCML_DS_16;

    fcml_st_encoded_modrm encoded_modrm;
    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0xF2 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );

    /* 32 bits - to 16 bits.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.offset.size = FCML_DS_32;
    modrm.address.offset.off32 = 0xFFFFFFF1;
    modrm.address.offset.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0xFF );
    STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );

    /* 64 bits - to 16 bits.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.offset.size = FCML_DS_64;
    modrm.address.offset.off64 = 0xFFFFFFFFFFFFFFF1ULL;
    modrm.address.offset.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0xFF );
    STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );

    /* 64 bits - to 16 bits, overflow.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.offset.size = FCML_DS_64;
    modrm.address.offset.off64 = 0x1FFFFFFFFFFFFFF1ULL;
    modrm.address.offset.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_VALUE_OUT_OF_RANGE );

    /* 32 bits - to 16 bits, overflow.*/

    fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );

    modrm.address.offset.size = FCML_DS_64;
    modrm.address.offset.off64 = 0x1FFFFFF1ULL;
    modrm.address.offset.is_signed = FCML_TRUE;
    modrm.address.address_form = FCML_AF_OFFSET;

    context.effective_address_size = FCML_DS_16;

    fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_VALUE_OUT_OF_RANGE );
}

/* Encode [BX+SI]*/
void fcml_tf_modrm_encoder_16_bit_encoding_1(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BX;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.size = FCML_DS_16;
	modrm.address.effective_address.index.reg = FCML_REG_SI;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0 );
}

/* Encode [BX+DI]*/
void fcml_tf_modrm_encoder_16_bit_encoding_2(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BX;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.size = FCML_DS_16;
	modrm.address.effective_address.index.reg = FCML_REG_DI;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 1 );
}

/* Encode [BP+SI]*/
void fcml_tf_modrm_encoder_16_bit_encoding_3(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BP;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.size = FCML_DS_16;
	modrm.address.effective_address.index.reg = FCML_REG_SI;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 2 );
}

/* Encode [BP+DI]*/
void fcml_tf_modrm_encoder_16_bit_encoding_4(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BP;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.size = FCML_DS_16;
	modrm.address.effective_address.index.reg = FCML_REG_DI;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 3 );
}

/* Encode [SI]*/
void fcml_tf_modrm_encoder_16_bit_encoding_5(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_SI;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 4 );
}

/* Encode [DI]*/
void fcml_tf_modrm_encoder_16_bit_encoding_6(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_DI;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 5 );
}

/* Encode [BP]*/
void fcml_tf_modrm_encoder_16_bit_encoding_7(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BP;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_INVALID_ADDRESSING_FORM );
}

/* Encode [BX]*/
void fcml_tf_modrm_encoder_16_bit_encoding_8(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BX;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 7 );

}

/* Encode [BX+DI]+disp8*/
void fcml_tf_modrm_encoder_16_bit_encoding_9(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BX;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.size = FCML_DS_16;
	modrm.address.effective_address.index.reg = FCML_REG_DI;
	modrm.address.effective_address.displacement.size = FCML_DS_8;
	modrm.address.effective_address.displacement.int8 = 0x12;
	modrm.address.effective_address.displacement.is_signed = FCML_FALSE;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x12 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x41 );

	modrm.address.effective_address.displacement.size = FCML_DS_16;
	modrm.address.effective_address.displacement.int16 = 0x12;

	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
    STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x12 );
}

/* Encode [BP]+disp8*/
void fcml_tf_modrm_encoder_16_bit_encoding_10(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BP;
	modrm.address.effective_address.displacement.size = FCML_DS_8;
	modrm.address.effective_address.displacement.int8 = (fcml_int8_t)0xFF;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xFF );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x46 );
}

/* Encode [SI]+disp16*/
void fcml_tf_modrm_encoder_16_bit_encoding_11(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_SI;
	modrm.address.effective_address.displacement.size = FCML_DS_16;
	modrm.address.effective_address.displacement.int16 = 0x0102;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x02 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x84 );
}

/* Encode [BX]+disp16*/
void fcml_tf_modrm_encoder_16_bit_encoding_12(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.size = FCML_DS_16;
	modrm.address.effective_address.base.reg = FCML_REG_BX;
	modrm.address.effective_address.displacement.size = FCML_DS_16;
	modrm.address.effective_address.displacement.int16 = (fcml_int16_t)0xFFF1;
	modrm.address.effective_address.displacement.is_signed = FCML_TRUE;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x47 );

	modrm.address.effective_address.displacement.int16 = 0x1FF1;

	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 2 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0xF1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x1F );
    STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x87 );
}

/* Encode DX, BP*/
void fcml_tf_modrm_encoder_16_bit_encoding_13(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_16;

	modrm.reg.is_not_null = FCML_TRUE;
	modrm.reg.value = FCML_REG_DI;
	modrm.reg_opcode = FCML_REG_BP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0xEF );
}

/* Encode [EAX], EAX*/
void fcml_tf_modrm_encoder_3264_bit_encoding_1(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EAX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EAX;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x00 );
}

/* Encode [ECX], EDI*/
void fcml_tf_modrm_encoder_3264_bit_encoding_2(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_ECX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EDI;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x39 );
}

/* Encode [RCX], RDI*/
void fcml_tf_modrm_encoder_3264_bit_encoding_3(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_64;
	context.op_mode = FCML_OM_64_BIT;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_RCX;
	modrm.address.effective_address.base.size = FCML_DS_64;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_RDI;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x39 );
}

/* Encode [ECX], RDI*/
void fcml_tf_modrm_encoder_3264_bit_encoding_4(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_64;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_ECX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_RDI;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_INVALID_ADDRESSING_FORM );
}

/* Encode [R12D], EDI (failed, because 32 bit addressing is used.)*/
void fcml_tf_modrm_encoder_3264_bit_encoding_5(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_32_BIT;
	context.choose_sib_encoding = FCML_TRUE;
	context.chosen_effective_address_size = FCML_DS_32;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_R12D;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EDI;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_INVALID_ADDRESSING_FORM );
}

/* Encode [01020304], ECX*/
/* Encode [0102], ECX*/
/* Encode [01], ECX*/
void fcml_tf_modrm_encoder_3264_bit_encoding_6(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.displacement.size = FCML_DS_32;
	modrm.address.effective_address.displacement.int32 = 0x01020304;
	modrm.address.address_form = FCML_AF_OFFSET;
	modrm.reg_opcode = FCML_REG_ECX;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x04 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x03 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x02 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x0D );
	STF_ASSERT_EQUAL( context.is_sib_alternative, FCML_TRUE );

	modrm.address.effective_address.displacement.size = FCML_DS_16;
	modrm.address.effective_address.displacement.int16 = 0x0102;
	modrm.reg_opcode = FCML_REG_ECX;

	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x02 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x0D );
	STF_ASSERT_EQUAL( context.is_sib_alternative, FCML_TRUE );

	modrm.address.effective_address.displacement.size = FCML_DS_8;
	modrm.address.effective_address.displacement.int8 = 0x01;
	modrm.address.address_form = FCML_AF_OFFSET;
	modrm.reg_opcode = FCML_REG_ECX;

	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x0D );
	STF_ASSERT_EQUAL( context.is_sib_alternative, FCML_TRUE );
}

/* Encode [EDI], R12D*/
void fcml_tf_modrm_encoder_3264_bit_encoding_7(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EDI;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_R12D;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x27 );
	STF_ASSERT_EQUAL( context.is_sib_alternative, FCML_TRUE );

}

/* Encode [EDX]+01020304, EBP*/
/* Encode [EDX]+0102, EBP*/
/* Encode [EDX]+01, EBP*/
void fcml_tf_modrm_encoder_3264_bit_encoding_8(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EDX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.displacement.size = FCML_DS_32;
	modrm.address.effective_address.displacement.int32 = 0x01020304;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EBP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x04 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x03 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x02 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0xAA );

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EDX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.displacement.size = FCML_DS_16;
	modrm.address.effective_address.displacement.int16 = 0x0102;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EBP;

	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x02 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0xAA );

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EDX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.displacement.size = FCML_DS_8;
	modrm.address.effective_address.displacement.int8 = 0x01;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EBP;

	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x6A );

	modrm.address.effective_address.base.type = FCML_REG_GPR;
    modrm.address.effective_address.base.reg = FCML_REG_EDX;
    modrm.address.effective_address.base.size = FCML_DS_32;
    modrm.address.effective_address.displacement.size = FCML_DS_32;
    modrm.address.effective_address.displacement.int32 = 0x01;
    modrm.address.address_form = FCML_AF_COMBINED;
    modrm.reg_opcode = FCML_REG_EBP;

    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
    STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 1 );
    STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x01 );
    STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
    STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
    STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
    STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
    STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
    STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x6A );
}

/* Encode EBP, R12D*/
void fcml_tf_modrm_encoder_3264_bit_encoding_9(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;

	modrm.reg.is_not_null = FCML_TRUE;
	modrm.reg.value = FCML_REG_EBP;
	modrm.reg_opcode = FCML_REG_R12D;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0xE5 );
}

/* Encode EBP+0x01, R12D*/
void fcml_tf_modrm_encoder_3264_bit_encoding_10(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.displacement.size = FCML_DS_8;
	modrm.address.effective_address.displacement.int32 = 0x01;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg.is_not_null = FCML_TRUE;
	modrm.reg.value = FCML_REG_EBP;
	modrm.reg_opcode = FCML_REG_R12D;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_INVALID_ADDRESSING_FORM );
}

/* Encode [R12D], EDI*/
void fcml_tf_modrm_encoder_3264_bit_encoding_11(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_R12D;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EDI;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x3c );
}

/* Encode [RAX], RDI (failed, 32 bits)*/
void fcml_tf_modrm_encoder_3264_bit_encoding_12(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_64;
	context.op_mode = FCML_OM_32_BIT;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_RAX;
	modrm.address.effective_address.base.size = FCML_DS_64;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_RDI;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_INVALID_ADDRESSING_FORM );
}

/* Encode [EAX+EBX], ESP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_1(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EAX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EBX;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_ESP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x18 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x24 );
}

/* Encode [EBP+EDX], ESP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_2(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EBP;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EDX;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_ESP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x15 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x24 );
}

/* Encode [EBP+EBP*2], ESP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_3(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EBP;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EBP;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.effective_address.scale_factor = 2;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_ESP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x6D );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x24 );
}

/* Encode [EBP+EBP*4], ESP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_4(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EBP;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EBP;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.effective_address.scale_factor = 4;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_ESP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0xAD );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x24 );
}

/* Encode [EBP+EBP*8], ESP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_5(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context = {0};
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_32_BIT;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EBP;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EBP;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.effective_address.scale_factor = 8;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_ESP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0xED );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x24 );
}

/* Encode [EBP+EBP*8]+disp8, ESP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_6(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.displacement.size = FCML_DS_8;
	modrm.address.effective_address.displacement.int8 = 0x50;
	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EBP;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EBP;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.effective_address.scale_factor = 8;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_ESP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x50 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0xED );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x64 );
}

/* Encode [EBP+EBP*8]+disp16, ESP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_7(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.displacement.size = FCML_DS_16;
	modrm.address.effective_address.displacement.int16 = 0x5051;
	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EBP;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EBP;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.effective_address.scale_factor = 8;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_ESP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x51 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x50 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0xED );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0xA4 );
}

/* Encode [EBP+EBP*8]+disp32, ESP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_8(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;

	modrm.address.effective_address.displacement.size = FCML_DS_32;
	modrm.address.effective_address.displacement.int32 = 0x50515253;
	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EBP;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_EBP;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.effective_address.scale_factor = 8;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_ESP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x53 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x52 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x51 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x50 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0xED );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0xA4 );
}

/* Encode [EDX]+01020304, EBP*/
/* Encode [EDX]+0102, EBP*/
/* Encode [EDX]+01, EBP*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_9(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.choose_sib_encoding = FCML_TRUE;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EDX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.displacement.size = FCML_DS_32;
	modrm.address.effective_address.displacement.int32 = 0x01020304;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EBP;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x04 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x03 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x02 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x22 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0xAC );

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EDX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.displacement.size = FCML_DS_16;
	modrm.address.effective_address.displacement.int16 = 0x0102;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EBP;

	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x02 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x22 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0xAC );

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_EDX;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.displacement.size = FCML_DS_8;
	modrm.address.effective_address.displacement.int8 = 0x01;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_EBP;

	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x22 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x6C );
}

/* Encode [R15D], R12D*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_10(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;
	context.choose_sib_encoding = FCML_TRUE;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_R15D;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_R12D;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x27 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x24 );
	STF_ASSERT_EQUAL( context.is_sib_alternative, FCML_TRUE );

}

/* Encode [R15D+R10D*4], R12D*/
void fcml_tf_modrm_sib_encoder_3264_bit_encoding_11(void) {
	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;
	context.choose_sib_encoding = FCML_TRUE;

	modrm.address.effective_address.base.type = FCML_REG_GPR;
	modrm.address.effective_address.base.reg = FCML_REG_R15D;
	modrm.address.effective_address.base.size = FCML_DS_32;
	modrm.address.effective_address.index.type = FCML_REG_GPR;
	modrm.address.effective_address.index.reg = FCML_REG_R10D;
	modrm.address.effective_address.index.size = FCML_DS_32;
	modrm.address.effective_address.scale_factor = 4;
	modrm.address.address_form = FCML_AF_COMBINED;
	modrm.reg_opcode = FCML_REG_R12D;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 1 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x97 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x24 );
	STF_ASSERT_EQUAL( context.is_sib_alternative, FCML_FALSE );

}

void fcml_tf_modrm_rip_encoder_3264_bit_encoding_1(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;
	context.choose_sib_encoding = FCML_TRUE;
	context.choose_rip_encoding = FCML_TRUE;

	modrm.address.effective_address.base.type = FCML_REG_UNDEFINED;
	modrm.address.effective_address.base.reg = 0;
	modrm.address.effective_address.base.size = 0;
	modrm.address.effective_address.index.type = FCML_REG_UNDEFINED;
	modrm.address.effective_address.index.reg = 0;
	modrm.address.effective_address.index.size = 0;
	modrm.address.effective_address.scale_factor = 0;
	modrm.reg_opcode = 0;
	modrm.address.offset.size = FCML_DS_32;
	modrm.address.offset.off32 = 0x00401008;
	modrm.address.address_form = FCML_AF_OFFSET;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	/* Displacement is not encoded yet.*/
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x05 );
	STF_ASSERT_EQUAL( encoded_modrm.is_rip, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.rip_address, 0x00401008 );

	fcml_uint8_t buff[4];
	fcml_st_memory_stream stream;
	stream.base_address = &buff;
	stream.offset = 0;
	stream.size = 4;
	error = fcml_fn_modrm_encode_rip_offset( &stream, 0x0000000000401000ULL, 8, &encoded_modrm );

	STF_ASSERT_EQUAL( buff[0], 0x00 );
	STF_ASSERT_EQUAL( buff[1], 0x00 );
	STF_ASSERT_EQUAL( buff[2], 0x00 );
	STF_ASSERT_EQUAL( buff[3], 0x00 );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

void fcml_tf_modrm_rip_encoder_3264_bit_encoding_2(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;
	context.choose_sib_encoding = FCML_TRUE;
	context.choose_rip_encoding = FCML_TRUE;

	modrm.address.effective_address.base.type = FCML_REG_UNDEFINED;
	modrm.address.effective_address.base.reg = 0;
	modrm.address.effective_address.base.size = 0;
	modrm.address.effective_address.index.type = FCML_REG_UNDEFINED;
	modrm.address.effective_address.index.reg = 0;
	modrm.address.effective_address.index.size = 0;
	modrm.address.effective_address.scale_factor = 0;
	modrm.reg_opcode = 0;
	modrm.address.offset.size = FCML_DS_32;
	modrm.address.address_form = FCML_AF_OFFSET;

	/* Dispalcement range sanity check.*/

	modrm.address.offset.size = FCML_DS_32;
	modrm.address.offset.off32 = 0xFFFFFFFFU;
	modrm.address.offset.is_signed = FCML_FALSE;
	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );

	modrm.address.offset.size = FCML_DS_32;
	modrm.address.offset.off32 = 0x0U;
	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );

	modrm.address.offset.size = FCML_DS_64;
	modrm.address.offset.off64 = 0x100000000U;
	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_VALUE_OUT_OF_RANGE );

	modrm.address.offset.size = FCML_DS_64;
	modrm.address.offset.off64 = 0xFFFFFFFFFFFFFFFFU;
	modrm.address.offset.is_signed = FCML_TRUE;
	error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );
	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );

	modrm.address.offset.size = FCML_DS_64;
    modrm.address.offset.off64 = 0xFFFFFFFFFFFFFFFFU;
    modrm.address.offset.is_signed = FCML_FALSE;
    error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );
    STF_ASSERT_EQUAL( error, FCML_CEH_GEC_VALUE_OUT_OF_RANGE );

}

void fcml_tf_modrm_rip_encoder_3264_bit_encoding_3(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;
	context.choose_sib_encoding = FCML_TRUE;
	context.choose_rip_encoding = FCML_TRUE;

	modrm.address.effective_address.base.type = FCML_REG_UNDEFINED;
	modrm.address.effective_address.base.reg = 0;
	modrm.address.effective_address.base.size = 0;
	modrm.address.effective_address.index.type = FCML_REG_UNDEFINED;
	modrm.address.effective_address.index.reg = 0;
	modrm.address.effective_address.index.size = 0;
	modrm.address.effective_address.scale_factor = 0;
	modrm.reg_opcode = 0;
	modrm.address.offset.size = FCML_DS_32;
	modrm.address.offset.off32 = 0x00000000;
	modrm.address.address_form = FCML_AF_OFFSET;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	/* Displacement is not encoded yet.*/
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x05 );
	STF_ASSERT_EQUAL( encoded_modrm.is_rip, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.rip_address, 0x00000000 );

	fcml_uint8_t buff[4];
	fcml_st_memory_stream stream;
	stream.base_address = &buff;
	stream.offset = 0;
	stream.size = 4;
	error = fcml_fn_modrm_encode_rip_offset( &stream, 0x0000000000401000ULL, 8, &encoded_modrm );

	STF_ASSERT_EQUAL( buff[0], 0xF8 );
	STF_ASSERT_EQUAL( buff[1], 0xEF );
	STF_ASSERT_EQUAL( buff[2], 0xBF );
	STF_ASSERT_EQUAL( buff[3], 0xFF );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

void fcml_tf_modrm_rip_encoder_3264_bit_encoding_4(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_32;
	context.op_mode = FCML_OM_64_BIT;
	context.choose_sib_encoding = FCML_TRUE;
	context.choose_rip_encoding = FCML_TRUE;

	modrm.address.effective_address.base.type = FCML_REG_UNDEFINED;
	modrm.address.effective_address.base.reg = 0;
	modrm.address.effective_address.base.size = 0;
	modrm.address.effective_address.index.type = FCML_REG_UNDEFINED;
	modrm.address.effective_address.index.reg = 0;
	modrm.address.effective_address.index.size = 0;
	modrm.address.effective_address.scale_factor = 0;
	modrm.reg_opcode = 0;
	modrm.address.offset.size = FCML_DS_32;
	modrm.address.offset.off32 = 0xFFFFFFFF;
	modrm.address.offset.is_signed = FCML_TRUE;
	modrm.address.address_form = FCML_AF_OFFSET;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	/* Displacement is not encoded yet.*/
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x05 );
	STF_ASSERT_EQUAL( encoded_modrm.is_rip, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.rip_address, 0xFFFFFFFFFFFFFFFFLL );

	fcml_uint8_t buff[4];
	fcml_st_memory_stream stream;
	stream.base_address = &buff;
	stream.offset = 0;
	stream.size = 4;
	error = fcml_fn_modrm_encode_rip_offset( &stream, 0x0000000000401000ULL, 8, &encoded_modrm );

	STF_ASSERT_EQUAL( buff[0], 0xF7 );
	STF_ASSERT_EQUAL( buff[1], 0xEF );
	STF_ASSERT_EQUAL( buff[2], 0xBF );
	STF_ASSERT_EQUAL( buff[3], 0xFF );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
}

void fcml_tf_modrm_rip_encoder_3264_bit_encoding_5(void) {

	fcml_st_modrm modrm;
	fcml_fn_env_memory_clear( &modrm, sizeof( modrm ) );
	fcml_st_encoded_modrm encoded_modrm;
	fcml_fn_env_memory_clear( &encoded_modrm, sizeof( encoded_modrm ) );
	fcml_st_modrm_encoder_context context;
	fcml_fn_env_memory_clear( &context, sizeof( context ) );
	context.effective_address_size = FCML_DS_64;
	context.op_mode = FCML_OM_64_BIT;
	context.choose_rip_encoding = FCML_FALSE;

	modrm.address.effective_address.base.type = FCML_REG_IP;
	modrm.address.effective_address.base.reg = 0;
	modrm.address.effective_address.base.size = FCML_DS_64;
	modrm.address.effective_address.scale_factor = 0;
	modrm.address.effective_address.displacement.size = FCML_DS_32;
	modrm.address.effective_address.displacement.int32 = 0x100;
	modrm.address.effective_address.displacement.is_signed = FCML_TRUE;
	modrm.address.address_form = FCML_AF_COMBINED;

	fcml_ceh_error error = fcml_fn_modrm_encode( &context, &modrm, &encoded_modrm );

	STF_ASSERT_EQUAL( error, FCML_CEH_GEC_NO_ERROR );
	/* Displacement is not encoded yet.*/
	STF_ASSERT_EQUAL( encoded_modrm.displacement_size, 4 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[0], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[1], 0x01 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[2], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.displacement[3], 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_b, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_r, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.ext_x, 0 );
	STF_ASSERT_EQUAL( encoded_modrm.sib.is_not_null, FCML_FALSE );
	STF_ASSERT_EQUAL( encoded_modrm.sib.value, 0x00 );
	STF_ASSERT_EQUAL( encoded_modrm.modrm, 0x05 );
	STF_ASSERT_EQUAL( encoded_modrm.is_rip, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.is_rip_encoded, FCML_TRUE );
	STF_ASSERT_EQUAL( encoded_modrm.rip_address, 0x0LL );
}

fcml_stf_test_case fctl_ti_modrm_encoder[] = {
	{ "fcml_tf_modrm_encoder_test_1", fcml_tf_modrm_encoder_test_1 },
	{ "fcml_tf_modrm_encoder_test_2", fcml_tf_modrm_encoder_test_2 },
	{ "fcml_tf_modrm_encoder_test_3", fcml_tf_modrm_encoder_test_3 },
	{ "fcml_tf_modrm_encoder_test_4", fcml_tf_modrm_encoder_test_4 },
	{ "fcml_tf_modrm_encoder_test_5", fcml_tf_modrm_encoder_test_5 },
	{ "fcml_tf_modrm_encoder_test_6", fcml_tf_modrm_encoder_test_6 },
	{ "fcml_tf_modrm_encoder_test_7", fcml_tf_modrm_encoder_test_7 },
	{ "fcml_tf_modrm_encoder_test_8", fcml_tf_modrm_encoder_test_8 },
	{ "fcml_tf_modrm_encoder_test_9", fcml_tf_modrm_encoder_test_9 },
	{ "fcml_tf_modrm_encoder_test_10", fcml_tf_modrm_encoder_test_10 },
	{ "fcml_tf_modrm_encoder_test_11", fcml_tf_modrm_encoder_test_11 },
	{ "fcml_tf_modrm_encoder_test_12", fcml_tf_modrm_encoder_test_12 },
	{ "fcml_tf_modrm_encoder_test_13", fcml_tf_modrm_encoder_test_13 },
	{ "fcml_tf_modrm_encoder_test_14", fcml_tf_modrm_encoder_test_14 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_1", fcml_tf_modrm_encoder_16_bit_encoding_1 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_2", fcml_tf_modrm_encoder_16_bit_encoding_2 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_3", fcml_tf_modrm_encoder_16_bit_encoding_3 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_4", fcml_tf_modrm_encoder_16_bit_encoding_4 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_5", fcml_tf_modrm_encoder_16_bit_encoding_5 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_6", fcml_tf_modrm_encoder_16_bit_encoding_6 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_7", fcml_tf_modrm_encoder_16_bit_encoding_7 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_8", fcml_tf_modrm_encoder_16_bit_encoding_8 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_9", fcml_tf_modrm_encoder_16_bit_encoding_9 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_10", fcml_tf_modrm_encoder_16_bit_encoding_10 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_11", fcml_tf_modrm_encoder_16_bit_encoding_11 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_12", fcml_tf_modrm_encoder_16_bit_encoding_12 },
	{ "fcml_tf_modrm_encoder_16_bit_encoding_13", fcml_tf_modrm_encoder_16_bit_encoding_13 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_1", fcml_tf_modrm_encoder_3264_bit_encoding_1 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_2", fcml_tf_modrm_encoder_3264_bit_encoding_2 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_3", fcml_tf_modrm_encoder_3264_bit_encoding_3 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_4", fcml_tf_modrm_encoder_3264_bit_encoding_4 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_5", fcml_tf_modrm_encoder_3264_bit_encoding_5 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_6", fcml_tf_modrm_encoder_3264_bit_encoding_6 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_7", fcml_tf_modrm_encoder_3264_bit_encoding_7 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_8", fcml_tf_modrm_encoder_3264_bit_encoding_8 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_9", fcml_tf_modrm_encoder_3264_bit_encoding_9 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_10", fcml_tf_modrm_encoder_3264_bit_encoding_10 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_11", fcml_tf_modrm_encoder_3264_bit_encoding_11 },
	{ "fcml_tf_modrm_encoder_3264_bit_encoding_12", fcml_tf_modrm_encoder_3264_bit_encoding_12 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_1", fcml_tf_modrm_sib_encoder_3264_bit_encoding_1 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_2", fcml_tf_modrm_sib_encoder_3264_bit_encoding_2 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_3", fcml_tf_modrm_sib_encoder_3264_bit_encoding_3 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_4", fcml_tf_modrm_sib_encoder_3264_bit_encoding_4 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_5", fcml_tf_modrm_sib_encoder_3264_bit_encoding_5 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_6", fcml_tf_modrm_sib_encoder_3264_bit_encoding_6 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_7", fcml_tf_modrm_sib_encoder_3264_bit_encoding_7 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_8", fcml_tf_modrm_sib_encoder_3264_bit_encoding_8 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_9", fcml_tf_modrm_sib_encoder_3264_bit_encoding_9 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_10", fcml_tf_modrm_sib_encoder_3264_bit_encoding_10 },
	{ "fcml_tf_modrm_sib_encoder_3264_bit_encoding_11", fcml_tf_modrm_sib_encoder_3264_bit_encoding_11 },
	{ "fcml_tf_modrm_rip_encoder_3264_bit_encoding_1", fcml_tf_modrm_rip_encoder_3264_bit_encoding_1 },
	{ "fcml_tf_modrm_rip_encoder_3264_bit_encoding_2", fcml_tf_modrm_rip_encoder_3264_bit_encoding_2 },
	{ "fcml_tf_modrm_rip_encoder_3264_bit_encoding_3", fcml_tf_modrm_rip_encoder_3264_bit_encoding_3 },
	{ "fcml_tf_modrm_rip_encoder_3264_bit_encoding_4", fcml_tf_modrm_rip_encoder_3264_bit_encoding_4 },
	{ "fcml_tf_modrm_rip_encoder_3264_bit_encoding_5", fcml_tf_modrm_rip_encoder_3264_bit_encoding_5 },
	FCML_STF_NULL_TEST
};

fcml_stf_test_suite fctl_si_modrm_encoder = {
	"suite-modrm-encoder", fcml_tf_modrm_encoder_suite_init, fcml_tf_modrm_encoder_suite_cleanup, fctl_ti_modrm_encoder
};
