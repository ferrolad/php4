/***********************************************************************/
/*                                                                     */
/*  FILE        :dezender.c                                            */
/*  DATE        :2005/08/10                                            */
/*  DESCRIPTION :opcode->php source code                               */
/*  PROJECT     :deZender                                              */
/*                                                                     */
/***********************************************************************/


#include "php.h"
#include "ext/standard/url.h"


#if 0
#define ZEND_NOP					0				/* NOP */
#define ZEND_ADD					1				/* + */
#define ZEND_SUB					2				/* - */
#define ZEND_MUL					3				/* * */
#define ZEND_DIV					4				/* / */
#define ZEND_MOD					5				/* % */
#define ZEND_SL						6				/* << */
#define ZEND_SR						7				/* >> */
#define ZEND_CONCAT					8				/* . */
#define ZEND_BW_OR					9				/* | */
#define ZEND_BW_AND					10				/* & */
#define ZEND_BW_XOR					11				/* ^ */
#define ZEND_BW_NOT					12				/* ~ */
#define ZEND_BOOL_NOT				13				/* ! */
#define ZEND_BOOL_XOR				14				/* XOR */
#define ZEND_IS_IDENTICAL			15				/* === */
#define ZEND_IS_NOT_IDENTICAL		16				/* !== */
#define ZEND_IS_EQUAL				17				/* == */
#define ZEND_IS_NOT_EQUAL			18				/* != */
#define ZEND_IS_SMALLER				19				/* < */
#define ZEND_IS_SMALLER_OR_EQUAL	20				/* <= */
#define ZEND_CAST					21				/* (int), (real), (string), (array), (object), (bool), (unset) */
#define ZEND_QM_ASSIGN				22				/* a?b:c */
#define ZEND_ASSIGN_ADD				23				/* += */
#define ZEND_ASSIGN_SUB				24				/* -= */
#define ZEND_ASSIGN_MUL				25				/* *= */
#define ZEND_ASSIGN_DIV				26				/* /= */
#define ZEND_ASSIGN_MOD				27				/* %= */
#define ZEND_ASSIGN_SL				28				/* <<= */
#define ZEND_ASSIGN_SR				29				/* >>= */
#define ZEND_ASSIGN_CONCAT			30				/* .= */
#define ZEND_ASSIGN_BW_OR			31				/* |= */
#define ZEND_ASSIGN_BW_AND			32				/* &= */
#define ZEND_ASSIGN_BW_XOR			33				/* ^= */
#define ZEND_PRE_INC				34				/* ++a */
#define ZEND_PRE_DEC				35				/* --a */
#define ZEND_POST_INC				36				/* a++ */
#define ZEND_POST_DEC				37				/* a-- */
#define ZEND_ASSIGN					38				/* = */
#define ZEND_ASSIGN_REF				39				/* =&a */
#define ZEND_ECHO					40				/* echo */
#define ZEND_PRINT					41				/* print */
#define ZEND_JMP					42				/* JMP */
#define ZEND_JMPZ					43				/* JMPZ */
#define ZEND_JMPNZ					44				/* JMPNZ */
#define ZEND_JMPZNZ					45				/* JMPZNZ */
#define ZEND_JMPZ_EX				46				/* JMPZ_EX */
#define ZEND_JMPNZ_EX				47				/* JMPNZ_EX */
#define ZEND_CASE					48				/* case */
#define ZEND_SWITCH_FREE			49				/* return, foreach, switch */
#define ZEND_BRK					50				/* break */
#define ZEND_CONT					51				/* continue */
#define ZEND_BOOL					52				/* ||, &&, switch(expr), default:  */
#define ZEND_INIT_STRING			53				/* '' */
#define ZEND_ADD_CHAR				54				/* . */
#define ZEND_ADD_STRING				55				/* . */
#define ZEND_ADD_VAR				56				/* . */
#define ZEND_BEGIN_SILENCE			57				/* @:begin */
#define ZEND_END_SILENCE			58				/* @:end */
#define ZEND_INIT_FCALL_BY_NAME		59				/* call function */
#define ZEND_DO_FCALL				60				/* call function */
#define ZEND_DO_FCALL_BY_NAME		61				/* call function */
#define ZEND_RETURN					62				/* return */
#define ZEND_RECV					63				/* function parameter */
#define ZEND_RECV_INIT				64				/* function parameter: static? */
#define ZEND_SEND_VAL				65				/* function call parameter: without variable  */
#define ZEND_SEND_VAR				66				/* function call parameter: variable */
#define ZEND_SEND_REF				67				/* function call parameter: &variable */
#define ZEND_NEW 					68				/* new */
#define ZEND_JMP_NO_CTOR			69				/* free, end of new */
#define ZEND_FREE					70				/* free */
#define ZEND_INIT_ARRAY				71				/* array pair list (a => b, ...) */
#define ZEND_ADD_ARRAY_ELEMENT		72				/* array pair list (a => b, ...) */
#define ZEND_INCLUDE_OR_EVAL		73				/* include, include_once, evel, require, require_once */
#define ZEND_UNSET_VAR				74				/* unset variable */
#define ZEND_UNSET_DIM_OBJ			75				/* unset dim, unset object */
#define ZEND_ISSET_ISEMPTY			76				/* isset, empty */
#define ZEND_FE_RESET				77				/* foreach */
#define ZEND_FE_FETCH				78				/* foreach */
#define ZEND_EXIT					79				/* exit */
#define ZEND_FETCH_R				80				/* fetch variable: read mode */
#define ZEND_FETCH_DIM_R			81				/* fetch dim: read mode */
#define ZEND_FETCH_OBJ_R			82				/* fetch object: read mode */
#define ZEND_FETCH_W				83				/* fetch variable: write mode */
#define ZEND_FETCH_DIM_W			84				/* fetch dim: write mode */
#define ZEND_FETCH_OBJ_W			85				/* fetch object: write mode */
#define ZEND_FETCH_RW				86				/* fetch variable: read/write mode */
#define ZEND_FETCH_DIM_RW			87				/* fetch dim: read/write mode */
#define ZEND_FETCH_OBJ_RW			88				/* fetch object: read/write mode */
#define ZEND_FETCH_IS				89				/* fetch variable: is mode */
#define ZEND_FETCH_DIM_IS			90				/* fetch dim: is mode */
#define ZEND_FETCH_OBJ_IS			91				/* fetch object: is mode */
#define ZEND_FETCH_FUNC_ARG			92				/* fetch variable: argument mode */
#define ZEND_FETCH_DIM_FUNC_ARG		93				/* fetch dim: argument mode */
#define ZEND_FETCH_OBJ_FUNC_ARG		94				/* fetch object: argument mode */
#define ZEND_FETCH_UNSET			95				/* fetch unset variable */
#define ZEND_FETCH_DIM_UNSET		96				/* fetch unset dim */
#define ZEND_FETCH_OBJ_UNSET		97				/* fetch unset object */
#define ZEND_FETCH_DIM_TMP_VAR		98				/* list, foreach */
#define ZEND_FETCH_CONSTANT			99				/* constant declaration */
#define ZEND_DECLARE_FUNCTION_OR_CLASS	100			/* function, class */
#define ZEND_EXT_STMT				101				/* ??? */
#define ZEND_EXT_FCALL_BEGIN		102				/* ??? */
#define ZEND_EXT_FCALL_END			103				/* ??? */
#define ZEND_EXT_NOP				104				/* ??? */
#define ZEND_TICKS					105				/* declare (ticks=?) */
#define ZEND_SEND_VAR_NO_REF		106				/* function call parameter: no reference */
#endif

/*-- for php 5.0.4 --*/
#define ZEND_CATCH					107
#define ZEND_THROW					108
#define ZEND_FETCH_CLASS			109
#define ZEND_CLONE					110
#define ZEND_INIT_CTOR_CALL			111
#define ZEND_INIT_METHOD_CALL		112
#define ZEND_INIT_STATIC_METHOD_CALL 113
#define ZEND_ISSET_ISEMPTY_VAR		114
#define ZEND_ISSET_ISEMPTY_DIM_OBJ	115
#define	ZEND_IMPORT_FUNCTION		116
#define	ZEND_IMPORT_CLASS			117
#define	ZEND_IMPORT_CONST			118
#define ZEND_PRE_INC_OBJ			132
#define ZEND_PRE_DEC_OBJ			133
#define ZEND_POST_INC_OBJ			134
#define ZEND_POST_DEC_OBJ			135
#define ZEND_ASSIGN_OBJ				136
#define ZEND_OP_DATA				137
#define ZEND_INSTANCEOF				138
//#define ZEND_DECLARE_CLASS				139
//#define ZEND_DECLARE_INHERITED_CLASS	140
//#define ZEND_DECLARE_FUNCTION			141
#define ZEND_RAISE_ABSTRACT_ERROR	142


#define DEZ_OP_NOP						0			/* NOP */
#define DEZ_OP_ADD						1   		/* + */
#define DEZ_OP_SUB						2   		/* - */
#define DEZ_OP_MUL						3   		/* * */
#define DEZ_OP_DIV						4   		/* / */
#define DEZ_OP_MOD						5   		/* % */
#define DEZ_OP_SL						6   		/* << */
#define DEZ_OP_SR						7   		/* >> */
#define DEZ_OP_CONCAT					8   		/* . */
#define DEZ_OP_BW_OR					9   		/* | */
#define DEZ_OP_BW_AND					10  		/* & */
#define DEZ_OP_BW_XOR					11  		/* ^ */
#define DEZ_OP_BW_NOT					12  		/* ~ */
#define DEZ_OP_BOOL_NOT					13  		/* ! */
#define DEZ_OP_IS_IDENTICAL				14  		/* === */
#define DEZ_OP_IS_NOT_IDENTICAL			15  		/* !== */
#define DEZ_OP_IS_EQUAL					16  		/* == */
#define DEZ_OP_IS_NOT_EQUAL				17  		/* != */
#define DEZ_OP_IS_SMALLER				18  		/* < */
#define DEZ_OP_IS_SMALLER_OR_EQUAL		19  		/* <= */
#define	DEZ_OP_CAST						20  		/* (double)a, (string)a, (array)a, (object)a, (bool)a, (unset)a */
#define DEZ_OP_QM_ASSIGN				21  		/* a?b:c */
#define DEZ_OP_ASSIGN_ADD				22  		/* += */
#define DEZ_OP_ASSIGN_SUB				23  		/* -= */
#define DEZ_OP_ASSIGN_MUL				24  		/* *= */
#define DEZ_OP_ASSIGN_DIV				25  		/* /= */
#define DEZ_OP_ASSIGN_MOD				26  		/* %= */
#define DEZ_OP_ASSIGN_SL				27  		/* <<= */
#define DEZ_OP_ASSIGN_SR				28  		/* >>= */
#define DEZ_OP_ASSIGN_CONCAT			29  		/* .= */
#define DEZ_OP_ASSIGN_BW_OR				30  		/* |= */
#define DEZ_OP_ASSIGN_BW_AND			31  		/* &= */
#define DEZ_OP_ASSIGN_BW_XOR			32  		/* ^= */
#define DEZ_OP_PRE_INC					33  		/* ++a */
#define DEZ_OP_PRE_DEC					34  		/* --a */
#define DEZ_OP_POST_INC					35  		/* a++ */
#define DEZ_OP_POST_DEC					36  		/* a-- */
#define DEZ_OP_ASSIGN					37  		/* = */
#define DEZ_OP_ASSIGN_REF				38  		/* =&a, static, global */
#define DEZ_OP_ECHO						39  		/* echo */
#define DEZ_OP_PRINT					40  		/* print */
#define	DEZ_OP_INCLUDE_OR_EVAL			41  		/* include, include_once, eval, require, require_once */
#define	DEZ_OP_LOGICAL_OR				42  		/* OR */
#define	DEZ_OP_LOGICAL_XOR				43  		/* XOR */
#define	DEZ_OP_LOGICAL_AND				44  		/* AND */
#define	DEZ_OP_NEW						45  		/* new */
#define	DEZ_OP_EXIT						46  		/* exit */
#define	DEZ_OP_IF						47  		/* if */
#define	DEZ_OP_ELSEIF					48  		/* elseif */
#define	DEZ_OP_ELSE						49  		/* else */
#define	DEZ_OP_DO						50  		/* do */
#define	DEZ_OP_WHILE					51  		/* while */
#define	DEZ_OP_FOR						52  		/* for */
#define	DEZ_OP_FOREACH					53  		/* foreach */
#define	DEZ_OP_DECLARE					54  		/* declare */
#define	DEZ_OP_AS						55  		/* as */
#define	DEZ_OP_SWITCH					56  		/* switch */
#define	DEZ_OP_CASE						57  		/* case */
#define	DEZ_OP_DEFAULT					58  		/* default */
#define	DEZ_OP_BREAK					59  		/* break */
#define	DEZ_OP_CONTINUE					60  		/* continue */
#define	DEZ_OP_OLD_FUNCTION				61  		/* old_function */
#define	DEZ_OP_FUNCTION					62  		/* function */
#define	DEZ_OP_CONST					63  		/* const */
#define	DEZ_OP_RETURN					64  		/* return */
#define	DEZ_OP_USE						65  		/* use */
#define	DEZ_OP_VAR						66  		/* var */
#define	DEZ_OP_UNSET					67  		/* unset */
#define	DEZ_OP_ISSET					68  		/* isset */
#define	DEZ_OP_EMPTY					69  		/* empty */
#define	DEZ_OP_CLASS					70  		/* class */
#define	DEZ_OP_EXTENDS					71  		/* extends */
#define	DEZ_OP_OBJECT_OPERATOR			72  		/* a->b */
#define	DEZ_OP_DOUBLE_ARROW				73  		/* a=>b */
#define	DEZ_OP_LIST						74  		/* list */
#define	DEZ_OP_ARRAY					75  		/* array */
#define	DEZ_OP_CLASS_C					76  		/* __CLASS__ */
#define	DEZ_OP_FUNC_C					77  		/* __FUNCTION__ */
#define	DEZ_OP_LINE						78  		/* __LINE__ */
#define	DEZ_OP_FILE						79  		/* __FILE__ */
#define	DEZ_OP_COMMENT					80  		/* comment */
#define	DEZ_OP_HEREDOC					81  		/* <<< */
#define	DEZ_OP_DOLLAR_OPEN_CURLY_BRACES	82  		/* ${...} */
#define	DEZ_OP_PAAMAYIM_NEKUDOTAYIM		83  		/* :: */
#define DEZ_OP_CALL_PARAM				84  		/* parameter of function calling */
#define DEZ_OP_CALL_INIT				85  		/* initialize function calling */
#define DEZ_OP_CALL						86  		/* function call */
#define DEZ_OP_CALL_EX					87  		/* function call (ex) */
#define DEZ_OP_BOOL						88  		/* end of OR, AND, ... */
#define DEZ_OP_FETCH_DIM				89  		/* fetch dim */
#define DEZ_OP_INIT_STRING				90  		/* init string */
#define DEZ_OP_FETCH					91  		/* fetch variable */
#define DEZ_OP_FETCH_CONSTANT			92  		/* fetch constant */
#define DEZ_OP_JMP						93  		/* jmp */
#define DEZ_OP_FUNC_PARAM				94  		/* parameter of function */
#define DEZ_OP_BEGIN_SILENCE			95  		/* @: begin */
#define DEZ_OP_END_SILENCE				96  		/* @: end */
#define DEZ_OP_LE						97  		/* list element */
#define DEZ_OP_UNKNOWN					98  		/* unknown op */

#define DEZ_IS_OPLINE					(1<<15)
#define DEZ_IS_CLASS					(1<<16)

#define OPC_STACK_SIZE					1024
#define OPCS_MAX_LEN					16
#define DEZ_VARS_NUM					1024
#define NODE_STACK_SIZE					2048


#define DEZ_ADD_NODE(x)					\
	m_dez_op_prev	= (x);				\
	(x)->prev		= m_dez_op_current;	\
	(x)->next		= NULL;				\
	if (m_dez_op_current != NULL)		\
	{									\
		m_dez_op_current->next	= (x);	\
	}									\
	m_dez_op_current		= (x);


#define DEZ_DEL_NODE(x)												\
	if ((x)->prev != NULL) (x)->prev->next = (x)->next;				\
	if ((x)->next != NULL) (x)->next->prev = (x)->prev;				\
	(x)->next = NULL;												\
	if (m_dez_op_current == (x)) m_dez_op_current = (x)->prev;		\
	dez_node_specs[(x)->dez_op].dez_node_free_func(x);


#define DEZ_DEL_CURRENT_NODE()			\
	m_dez_op_current		= m_dez_op_current->prev;	\
	dez_node_specs[m_dez_op_current->next->dez_op].dez_node_free_func(m_dez_op_current->next);	\
	m_dez_op_current->next	= NULL;


#define ZEND_LINENUM(x)					\
	((x) == NULL ? 0 : ((x) >= (zend_op *)m_zend_op_dup && (x) < (zend_op *)(m_zend_op_dup+m_zend_op_dup_num) ? *((int *)((x)+1)) : ((x) - m_zend_op_start)))


typedef struct
{
	zend_op zop;
	int linenum;
} DEZ_ZEND_OP_DUP;

typedef struct
{
	int index;
	char varname[1024];
} DEZ_VAR;

typedef struct DEZ_EG_VAR_NAME_t
{
	unsigned type;
	char *var;
	unsigned len;
	unsigned other;
} DEZ_EG_VAR_NAME;

typedef struct DEZ_EG_FUNC_NAME_t
{
	unsigned type;
	char *func;
	unsigned len;
	unsigned other;
} DEZ_EG_FUNC_NAME;

typedef struct DEZ_EG_FUNC_t
{
	DEZ_EG_FUNC_NAME *funcs;
	unsigned func_num;
	unsigned r2;
	unsigned r3;
} DEZ_EG_FUNC;

typedef struct DEZ_EG_E_t
{
	unsigned r1;
	unsigned r2;
	unsigned r3;
	unsigned r4;
	unsigned r5;
	unsigned r6;
	void *p1;
	unsigned char *zop2op;
	void *p2;
	unsigned r7;
	void *p3;
	unsigned r8;
} DEZ_EG_E;

typedef struct DEZ_EG_RESERVED_t
{
	DEZ_EG_VAR_NAME	*vars;
	unsigned		var_num;
	unsigned		r1;
	DEZ_EG_FUNC		*funcs;
	unsigned		r2;
	DEZ_EG_E		*e;
	void			*p3;
} DEZ_EG_RESERVED;

/*-- type: dez node --*/
typedef struct DEZ_NODE_s
{
	unsigned char dez_op;							/* dez op code */
	zend_op *zop;
	void *content;									/* dez node content */
	struct DEZ_NODE_s *prev;						/* pointer the previous dez node */
	struct DEZ_NODE_s *next;						/* pointer the next dez node */
} DEZ_NODE;

/*-- dez node content: expression --*/
typedef struct DEZ_NODE_EXPR_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	DEZ_NODE *op1_node;
	DEZ_NODE *op2_node;
} DEZ_NODE_EXPR;

/*-- dez node content: if --*/
typedef struct DEZ_NODE_IF_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	DEZ_NODE *op1_node;
	DEZ_NODE *op2_node;
	int dest;
} DEZ_NODE_IF;

/*-- dez node content: for --*/
typedef struct DEZ_NODE_FOR_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	DEZ_NODE *before_node;
	DEZ_NODE *cond_node;
	DEZ_NODE *after_node;
} DEZ_NODE_FOR;

/*-- dez node content: => --*/
typedef struct DEZ_NODE_DA_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	DEZ_NODE *key_node;
	DEZ_NODE *value_node;
	DEZ_NODE *next_node;
} DEZ_NODE_DA;

/*-- dez node content: foreach --*/
typedef struct DEZ_NODE_FOREACH_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	DEZ_NODE *source_node;
	DEZ_NODE *key_node;
	DEZ_NODE *value_node;
} DEZ_NODE_FOREACH;

/*-- dez node content: function --*/
typedef struct DEZ_NODE_FUNCTION_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	DEZ_NODE *param_node;
	char *name;
	DEZ_VAR m_dez_vars[DEZ_VARS_NUM];
	int m_dez_var_num;
	zend_op_array *op_array;
} DEZ_NODE_FUNCTION;

/*-- dez node content: class --*/
typedef struct DEZ_NODE_CLASS_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	char *name;
	zend_class_entry *parent;
} DEZ_NODE_CLASS;

/*-- dez node content: var --*/
typedef struct DEZ_NODE_VAR_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	Bucket *property;
} DEZ_NODE_VAR;

/*-- dez node content: list element --*/
typedef struct DEZ_NODE_LE_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	DEZ_NODE *a_node;
	int pos;
} DEZ_NODE_LE;

/*-- dez node content: list --*/
typedef struct DEZ_NODE_LIST_s
{
	DEZ_NODE *branch_node;							/* must is first one */
	DEZ_NODE *le_node;
	DEZ_NODE *dest_node;
	int level;
} DEZ_NODE_LIST;


typedef int (*DEZ_NODE_CVT_FUNC)(unsigned char dez_op, zend_op *pzop);
typedef int (*DEZ_NODE_OUTPUT_FUNC)(DEZ_NODE *pdez_node);
typedef void (*DEZ_NODE_FREE_FUNC)(DEZ_NODE *pdez_node);


static int dez_node_cvt_nop  (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_expr (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_qm_assign (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_if (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_do (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_for (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_foreach (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_case (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_default (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_function_or_class (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_double_arrow (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_array (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_heredoc (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_dollar_open_curly_braces (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_call (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_bool (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_jmp (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_func_param (unsigned char dez_op, zend_op *pzop);
static int dez_node_cvt_unknown (unsigned char dez_op, zend_op *pzop);

static int dez_node_output_nop(DEZ_NODE *pdez_node);
static int dez_node_output_expr(DEZ_NODE *pdez_node);
static int dez_node_output_cast(DEZ_NODE *pdez_node);
static int dez_node_output_pre(DEZ_NODE *pdez_node);
static int dez_node_output_pre2(DEZ_NODE *pdez_node);
static int dez_node_output_post(DEZ_NODE *pdez_node);
static int dez_node_output_qm_assign(DEZ_NODE *pdez_node);
static int dez_node_output_assign(DEZ_NODE *pdez_node);
static int dez_node_output_assign_ref(DEZ_NODE *pdez_node);
static int dez_node_output_include_or_eval(DEZ_NODE *pdez_node);
static int dez_node_output_or_and(DEZ_NODE *pdez_node);
static int dez_node_output_new(DEZ_NODE *pdez_node);
static int dez_node_output_exit(DEZ_NODE *pdez_node);
static int dez_node_output_if(DEZ_NODE *pdez_node);
static int dez_node_output_do(DEZ_NODE *pdez_node);
static int dez_node_output_for(DEZ_NODE *pdez_node);
static int dez_node_output_foreach(DEZ_NODE *pdez_node);
static int dez_node_output_declare(DEZ_NODE *pdez_node);
static int dez_node_output_case(DEZ_NODE *pdez_node);
static int dez_node_output_default(DEZ_NODE *pdez_node);
static int dez_node_output_function(DEZ_NODE *pdez_node);
static int dez_node_output_var(DEZ_NODE *pdez_node);
static int dez_node_output_unset(DEZ_NODE *pdez_node);
static int dez_node_output_isset_or_empty(DEZ_NODE *pdez_node);
static int dez_node_output_class(DEZ_NODE *pdez_node);
static int dez_node_output_double_arrow(DEZ_NODE *pdez_node);
static int dez_node_output_list(DEZ_NODE *pdez_node);
static int dez_node_output_array(DEZ_NODE *pdez_node);
static int dez_node_output_heredoc(DEZ_NODE *pdez_node);
static int dez_node_output_dollar_open_curly_braces(DEZ_NODE *pdez_node);
static int dez_node_output_call_param(DEZ_NODE *pdez_node);
static int dez_node_output_call_init(DEZ_NODE *pdez_node);
static int dez_node_output_call(DEZ_NODE *pdez_node);
static int dez_node_output_call_ex(DEZ_NODE *pdez_node);
static int dez_node_output_fetch_dim(DEZ_NODE *pdez_node);
static int dez_node_output_init_string(DEZ_NODE *pdez_node);
static int dez_node_output_fetch_constant(DEZ_NODE *pdez_node);
static int dez_node_output_func_param(DEZ_NODE *pdez_node);
static int dez_node_output_property(DEZ_NODE *pdez_node);
static int dez_node_output_le(DEZ_NODE *pdez_node);
static int dez_node_output_unknown(DEZ_NODE *pdez_node);

static void dez_node_free_nop (DEZ_NODE *pdez_node);
static void dez_node_free_expr (DEZ_NODE *pdez_node);
static void dez_node_free_if (DEZ_NODE *pdez_node);
static void dez_node_free_for (DEZ_NODE *pdez_node);
static void dez_node_free_foreach (DEZ_NODE *pdez_node);
static void dez_node_free_case (DEZ_NODE *pdez_node);
static void dez_node_free_default (DEZ_NODE *pdez_node);
static void dez_node_free_function (DEZ_NODE *pdez_node);
static void dez_node_free_var (DEZ_NODE *pdez_node);
static void dez_node_free_class (DEZ_NODE *pdez_node);
static void dez_node_free_da (DEZ_NODE *pdez_node);
static void dez_node_free_list (DEZ_NODE *pdez_node);
static void dez_node_free_heredoc (DEZ_NODE *pdez_node);
static void dez_node_free_dollar_open_curly_braces (DEZ_NODE *pdez_node);
static void dez_node_free_property(DEZ_NODE *pdez_node);
static void dez_node_free_le (DEZ_NODE *pdez_node);
static void dez_node_free_unknown (DEZ_NODE *pdez_node);


typedef struct
{
	char *desc;
	DEZ_NODE_CVT_FUNC		dez_node_cvt_func;			/* the node convert function */
	DEZ_NODE_OUTPUT_FUNC 	dez_node_output_func;		/* the node output function */
	DEZ_NODE_FREE_FUNC		dez_node_free_func;			/* the node free function */
} DEZ_NODE_SPEC;

typedef struct
{
	unsigned char dez_op;							/* dez op code */
	short opcs_len;                 				/* the length of opcs[] */
	unsigned char opcs[OPCS_MAX_LEN];				/* the matching zend op codes */
} DEZ_OP_TYPE;

typedef struct DEZ_BRK_CNT_NODE_s
{
	const DEZ_NODE *node;							/* pointer to if(false) node */
	struct DEZ_BRK_CNT_NODE_s *prev;
	struct DEZ_BRK_CNT_NODE_s *next;
} DEZ_BRK_CNT_NODE;


static DEZ_VAR m_dez_vars[DEZ_VARS_NUM];
static int m_dez_var_num = 0;

static char *ZEND_OP_STRING[] = 
{
	"ZEND_NOP                         ",
	"ZEND_ADD                         ",
	"ZEND_SUB                         ",
	"ZEND_MUL                         ",
	"ZEND_DIV                         ",
	"ZEND_MOD                         ",
	"ZEND_SL                          ",
	"ZEND_SR                          ",
	"ZEND_CONCAT                      ",
	"ZEND_BW_OR                       ",
	"ZEND_BW_AND                      ",
	"ZEND_BW_XOR                      ",
	"ZEND_BW_NOT                      ",
	"ZEND_BOOL_NOT                    ",
	"ZEND_BOOL_XOR                    ",
	"ZEND_IS_IDENTICAL                ",
	"ZEND_IS_NOT_IDENTICAL            ",
	"ZEND_IS_EQUAL                    ",
	"ZEND_IS_NOT_EQUAL                ",
	"ZEND_IS_SMALLER                  ",
	"ZEND_IS_SMALLER_OR_EQUAL         ",
	"ZEND_CAST                        ",
	"ZEND_QM_ASSIGN                   ",
	"ZEND_ASSIGN_ADD                  ",
	"ZEND_ASSIGN_SUB                  ",
	"ZEND_ASSIGN_MUL                  ",
	"ZEND_ASSIGN_DIV                  ",
	"ZEND_ASSIGN_MOD                  ",
	"ZEND_ASSIGN_SL                   ",
	"ZEND_ASSIGN_SR                   ",
	"ZEND_ASSIGN_CONCAT               ",
	"ZEND_ASSIGN_BW_OR                ",
	"ZEND_ASSIGN_BW_AND               ",
	"ZEND_ASSIGN_BW_XOR               ",
	"ZEND_PRE_INC                     ",
	"ZEND_PRE_DEC                     ",
	"ZEND_POST_INC                    ",
	"ZEND_POST_DEC                    ",
	"ZEND_ASSIGN                      ",
	"ZEND_ASSIGN_REF                  ",
	"ZEND_ECHO                        ",
	"ZEND_PRINT                       ",
	"ZEND_JMP                         ",
	"ZEND_JMPZ                        ",
	"ZEND_JMPNZ                       ",
	"ZEND_JMPZNZ                      ",
	"ZEND_JMPZ_EX                     ",
	"ZEND_JMPNZ_EX                    ",
	"ZEND_CASE                        ",
	"ZEND_SWITCH_FREE                 ",
	"ZEND_BRK                         ",
	"ZEND_CONT                        ",
	"ZEND_BOOL                        ",
	"ZEND_INIT_STRING                 ",
	"ZEND_ADD_CHAR                    ",
	"ZEND_ADD_STRING                  ",
	"ZEND_ADD_VAR                     ",
	"ZEND_BEGIN_SILENCE               ",
	"ZEND_END_SILENCE                 ",
	"ZEND_INIT_FCALL_BY_NAME          ",
	"ZEND_DO_FCALL                    ",
	"ZEND_DO_FCALL_BY_NAME            ",
	"ZEND_RETURN                      ",
	"ZEND_RECV                        ",
	"ZEND_RECV_INIT                   ",
	"ZEND_SEND_VAL                    ",
	"ZEND_SEND_VAR                    ",
	"ZEND_SEND_REF                    ",
	"ZEND_NEW                         ",
	"ZEND_JMP_NO_CTOR                 ",
	"ZEND_FREE                        ",
	"ZEND_INIT_ARRAY                  ",
	"ZEND_ADD_ARRAY_ELEMENT           ",
	"ZEND_INCLUDE_OR_EVAL             ",
	"ZEND_UNSET_VAR                   ",
	"ZEND_UNSET_DIM_OBJ               ",
	"ZEND_ISSET_ISEMPTY               ",
	"ZEND_FE_RESET                    ",
	"ZEND_FE_FETCH                    ",
	"ZEND_EXIT                        ",
	"ZEND_FETCH_R                     ",
	"ZEND_FETCH_DIM_R                 ",
	"ZEND_FETCH_OBJ_R                 ",
	"ZEND_FETCH_W                     ",
	"ZEND_FETCH_DIM_W                 ",
	"ZEND_FETCH_OBJ_W                 ",
	"ZEND_FETCH_RW                    ",
	"ZEND_FETCH_DIM_RW                ",
	"ZEND_FETCH_OBJ_RW                ",
	"ZEND_FETCH_IS                    ",
	"ZEND_FETCH_DIM_IS                ",
	"ZEND_FETCH_OBJ_IS                ",
	"ZEND_FETCH_FUNC_ARG              ",
	"ZEND_FETCH_DIM_FUNC_ARG          ",
	"ZEND_FETCH_OBJ_FUNC_ARG          ",
	"ZEND_FETCH_UNSET                 ",
	"ZEND_FETCH_DIM_UNSET             ",
	"ZEND_FETCH_OBJ_UNSET             ",
	"ZEND_FETCH_DIM_TMP_VAR           ",
	"ZEND_FETCH_CONSTANT              ",
	"ZEND_DECLARE_FUNCTION_OR_CLASS   ",
	"ZEND_EXT_STMT                    ",
	"ZEND_EXT_FCALL_BEGIN             ",
	"ZEND_EXT_FCALL_END               ",
	"ZEND_EXT_NOP                     ",
	"ZEND_TICKS                       ",
	"ZEND_SEND_VAR_NO_REF             ",
	"ZEND_CATCH	                      ",
	"ZEND_THROW	                      ",
	"ZEND_FETCH_CLASS	              ",
	"ZEND_CLONE	                      ",
	"ZEND_INIT_CTOR_CALL	          ",
	"ZEND_INIT_METHOD_CALL	          ",
	"ZEND_INIT_STATIC_METHOD_CALL     ",
	"ZEND_ISSET_ISEMPTY_VAR	          ",
	"ZEND_ISSET_ISEMPTY_DIM_OBJ	      ",
	"ZEND_IMPORT_FUNCTION	          ",
	"ZEND_IMPORT_CLASS	              ",
	"ZEND_IMPORT_CONST	              ",
	"ZEND_PRE_INC_OBJ	              ",
	"ZEND_PRE_DEC_OBJ	              ",
	"ZEND_POST_INC_OBJ	              ",
	"ZEND_POST_DEC_OBJ	              ",
	"ZEND_ASSIGN_OBJ	              ",
	"ZEND_OP_DATA	                  ",
	"ZEND_INSTANCEOF	              ",
	"ZEND_DECLARE_CLASS	              ",
	"ZEND_DECLARE_INHERITED_CLASS	  ",  
	"ZEND_DECLARE_FUNCTION	          ",  
	"ZEND_RAISE_ABSTRACT_ERROR	      "
};


static DEZ_NODE_SPEC dez_node_specs[] = 
{
	{"", dez_node_cvt_nop, dez_node_output_nop, dez_node_free_nop},                                          /* DEZ_OP_NOP*/
	{" + ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                        /* DEZ_OP_ADD*/
	{" - ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                        /* DEZ_OP_SUB*/
	{" * ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                        /* DEZ_OP_MUL*/
	{" / ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                        /* DEZ_OP_DIV*/
	{" % ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                        /* DEZ_OP_MOD*/
	{" << ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                            /* DEZ_OP_SL*/
	{" >> ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                            /* DEZ_OP_SR*/
	{".", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                    /* DEZ_OP_CONCAT*/
	{" | ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                      /* DEZ_OP_BW_OR    */
	{" & ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                    /* DEZ_OP_BW_AND*/
	{" ^ ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                    /* DEZ_OP_BW_XOR*/
	{"~", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                    /* DEZ_OP_BW_NOT*/
	{"!", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                /* DEZ_OP_BOOL_NOT    */
	{" === ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                        /* DEZ_OP_IS_IDENTICAL    */
	{" !== ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                /* DEZ_OP_IS_NOT_IDENTICAL    */
	{" == ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                                /* DEZ_OP_IS_EQUAL    */
	{" != ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                        /* DEZ_OP_IS_NOT_EQUAL    */
	{" < ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                            /* DEZ_OP_IS_SMALLER*/
	{" <= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},          			/* DEZ_OP_IS_SMALLER_OR_EQUAL*/
	{"(xxx)a", dez_node_cvt_expr, dez_node_output_cast, dez_node_free_expr},                                        /* DEZ_OP_CAST    */
	{"a?b:c", dez_node_cvt_qm_assign, dez_node_output_qm_assign, dez_node_free_expr},                              /* DEZ_OP_QM_ASSIGN    */
	{" += ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                            /* DEZ_OP_ASSIGN_ADD*/
	{" -= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                            /* DEZ_OP_ASSIGN_SUB*/
	{" *= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                            /* DEZ_OP_ASSIGN_MUL*/
	{" /= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                            /* DEZ_OP_ASSIGN_DIV*/
	{" %= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                            /* DEZ_OP_ASSIGN_MOD*/
	{" <<= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                              /* DEZ_OP_ASSIGN_SL    */
	{" >>= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                              /* DEZ_OP_ASSIGN_SR    */
	{" .= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                      /* DEZ_OP_ASSIGN_CONCAT    */
	{" |= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                        /* DEZ_OP_ASSIGN_BW_OR    */
	{" &= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                      /* DEZ_OP_ASSIGN_BW_AND    */
	{" ^= ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                      /* DEZ_OP_ASSIGN_BW_XOR    */
	{"++", dez_node_cvt_expr, dez_node_output_pre, dez_node_free_expr},                                  /* DEZ_OP_PRE_INC*/
	{"--", dez_node_cvt_expr, dez_node_output_pre, dez_node_free_expr},                                  /* DEZ_OP_PRE_DEC*/
	{"++", dez_node_cvt_expr, dez_node_output_post, dez_node_free_expr},                                /* DEZ_OP_POST_INC    */
	{"--", dez_node_cvt_expr, dez_node_output_post, dez_node_free_expr},                                /* DEZ_OP_POST_DEC    */
	{" = ", dez_node_cvt_expr, dez_node_output_assign, dez_node_free_expr},                                    /* DEZ_OP_ASSIGN*/
	{" = &", dez_node_cvt_expr, dez_node_output_assign_ref, dez_node_free_expr},                            /* DEZ_OP_ASSIGN_REF*/
	{"echo ", dez_node_cvt_expr, dez_node_output_pre, dez_node_free_expr},                                        /* DEZ_OP_ECHO    */
	{"print ", dez_node_cvt_expr, dez_node_output_pre, dez_node_free_expr},                                      /* DEZ_OP_PRINT    */
	{"", dez_node_cvt_expr, dez_node_output_include_or_eval, dez_node_free_expr},                  /* DEZ_OP_INCLUDE_OR_EVAL*/
	{" OR ", dez_node_cvt_expr, dez_node_output_or_and, dez_node_free_expr},                            /* DEZ_OP_LOGICAL_OR*/
	{" XOR ", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},                          /* DEZ_OP_LOGICAL_XOR*/
	{" AND ", dez_node_cvt_expr, dez_node_output_or_and, dez_node_free_expr},                          /* DEZ_OP_LOGICAL_AND*/
	{"new ", dez_node_cvt_expr, dez_node_output_new, dez_node_free_expr},                                          /* DEZ_OP_NEW*/
	{"exit", dez_node_cvt_expr, dez_node_output_exit, dez_node_free_expr},                                        /* DEZ_OP_EXIT    */
	{"if ", dez_node_cvt_if, dez_node_output_if, dez_node_free_if},                                            /* DEZ_OP_IF*/
	{"elseif ", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                    /* DEZ_OP_ELSEIF*/
	{"else", dez_node_cvt_expr, dez_node_output_pre, dez_node_free_expr},                                        /* DEZ_OP_ELSE    */
	{"do", dez_node_cvt_do, dez_node_output_do, dez_node_free_expr},                                            /* DEZ_OP_DO*/
	{"while ", dez_node_cvt_unknown, dez_node_output_if, dez_node_free_if},                                      /* DEZ_OP_WHILE    */
	{"for ", dez_node_cvt_for, dez_node_output_for, dez_node_free_for},                                          /* DEZ_OP_FOR*/
	{"foreach ", dez_node_cvt_foreach, dez_node_output_foreach, dez_node_free_foreach},                                  /* DEZ_OP_FOREACH*/
	{"declare ", dez_node_cvt_expr, dez_node_output_declare, dez_node_free_expr},                                  /* DEZ_OP_DECLARE*/
	{"", dez_node_cvt_unknown, dez_node_output_pre, dez_node_free_expr},                                            /* DEZ_OP_AS*/
	{"switch ", dez_node_cvt_unknown, dez_node_output_if, dez_node_free_if},                                    /* DEZ_OP_SWITCH*/
	{"case ", dez_node_cvt_case, dez_node_output_case, dez_node_free_case},                                        /* DEZ_OP_CASE    */
	{"default:", dez_node_cvt_default, dez_node_output_default, dez_node_free_default},                                  /* DEZ_OP_DEFAULT*/
	{"break", dez_node_cvt_expr, dez_node_output_pre2, dez_node_free_expr},                                      /* DEZ_OP_BREAK    */
	{"continue", dez_node_cvt_expr, dez_node_output_pre2, dez_node_free_expr},                                /* DEZ_OP_CONTINUE    */
	{"old_function", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                        /* DEZ_OP_OLD_FUNCTION    */
	{"function ", dez_node_cvt_function_or_class, dez_node_output_function, dez_node_free_function},                                /* DEZ_OP_FUNCTION    */
	{"const", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                      /* DEZ_OP_CONST    */
	{"return ", dez_node_cvt_expr, dez_node_output_pre, dez_node_free_expr},                                    /* DEZ_OP_RETURN*/
	{"use", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                          /* DEZ_OP_USE*/
	{"var ", dez_node_cvt_unknown, dez_node_output_var, dez_node_free_var},                                          /* DEZ_OP_VAR*/
	{"unset ", dez_node_cvt_expr, dez_node_output_unset, dez_node_free_expr},                                      /* DEZ_OP_UNSET    */
	{"isset ", dez_node_cvt_expr, dez_node_output_isset_or_empty, dez_node_free_expr},                                      /* DEZ_OP_ISSET    */
	{"empty ", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                      /* DEZ_OP_EMPTY    */
	{"class ", dez_node_cvt_function_or_class, dez_node_output_class, dez_node_free_class},                                      /* DEZ_OP_CLASS    */
	{"extends", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                  /* DEZ_OP_EXTENDS*/
	{"->", dez_node_cvt_expr, dez_node_output_expr, dez_node_free_expr},    				              /* DEZ_OP_OBJECT_OPERATOR*/
	{" => ", dez_node_cvt_double_arrow, dez_node_output_double_arrow, dez_node_free_da},                        /* DEZ_OP_DOUBLE_ARROW    */
	{"list ", dez_node_cvt_unknown, dez_node_output_list, dez_node_free_list},                                        /* DEZ_OP_LIST    */
	{"array ", dez_node_cvt_array, dez_node_output_array, dez_node_free_da},                                      /* DEZ_OP_ARRAY    */
	{"__CLASS__", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                  /* DEZ_OP_CLASS_C*/
	{"__FUNCTION__", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                    /* DEZ_OP_FUNC_C*/
	{"__LINE__", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                        /* DEZ_OP_LINE    */
	{"__FILE__", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                        /* DEZ_OP_FILE    */
	{"", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                  /* DEZ_OP_COMMENT*/
/****/	{"<<<", dez_node_cvt_heredoc, dez_node_output_heredoc, dez_node_free_heredoc},                                  /* DEZ_OP_HEREDOC*/
/****/	{"", dez_node_cvt_dollar_open_curly_braces, dez_node_output_dollar_open_curly_braces, dez_node_free_dollar_open_curly_braces},/* DEZ_OP_DOLLAR_OPEN_CURLY_BRACES  */
	{"::", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown},                                /* DEZ_OP_PAAMAYIM_NEKUDOTAYIM    */
	{"", dez_node_cvt_expr, dez_node_output_call_param, dez_node_free_expr},                                        /* DEZ_OP_CALL_PARAM    */
	{"", dez_node_cvt_expr, dez_node_output_call_init, dez_node_free_expr},                                        /* DEZ_OP_CALL_INIT    */
	{"", dez_node_cvt_call, dez_node_output_call, dez_node_free_expr},                                        /* DEZ_OP_CALL    */
	{"", dez_node_cvt_call, dez_node_output_call_ex, dez_node_free_expr},                                        /* DEZ_OP_CALL_EX    */
	{"", dez_node_cvt_bool, dez_node_output_unknown, dez_node_free_expr},                                        /* DEZ_OP_BOOL    */
	{"a[b]", dez_node_cvt_expr, dez_node_output_fetch_dim, dez_node_free_expr},                                        /* DEZ_OP_FETCH_DIM    */
	{"''", dez_node_cvt_expr, dez_node_output_init_string, dez_node_free_expr},                                        /* DEZ_OP_INIT_STRING    */
	{"$", dez_node_cvt_expr, dez_node_output_pre, dez_node_free_expr},                                        /* DEZ_OP_FETCH    */
	{"", dez_node_cvt_expr, dez_node_output_fetch_constant, dez_node_free_expr},                                        /* DEZ_OP_FETCH_CONSTANT    */
	{"jmp", dez_node_cvt_jmp, dez_node_output_pre, dez_node_free_if},                                        /* DEZ_OP_JMP    */
	{"", dez_node_cvt_func_param, dez_node_output_func_param, dez_node_free_expr},                                        /* DEZ_OP_FUNC_PARAM    */
	{"@", dez_node_cvt_expr, dez_node_output_unknown, dez_node_free_expr},                                        /* DEZ_OP_BEGIN_SILENCE    */
	{"", dez_node_cvt_expr, dez_node_output_unknown, dez_node_free_expr},                                        /* DEZ_OP_END_SILENCE    */
	{"", dez_node_cvt_unknown, dez_node_output_le, dez_node_free_le},                                        /* DEZ_OP_END_SILENCE    */
	{"", dez_node_cvt_unknown, dez_node_output_unknown, dez_node_free_unknown}                                   /* DEZ_OP_UNKNOWN    */
};


static DEZ_OP_TYPE dez_op_types[] = 
{
	{DEZ_OP_NOP						, 1, {ZEND_NOP}},
	{DEZ_OP_NOP						, 1, {ZEND_FREE}},
	{DEZ_OP_NOP						, 1, {ZEND_SWITCH_FREE}},
	{DEZ_OP_NOP						, 1, {ZEND_INIT_CTOR_CALL}},
	{DEZ_OP_ADD						, 1, {ZEND_ADD}},
	{DEZ_OP_SUB						, 1, {ZEND_SUB}},
	{DEZ_OP_MUL						, 1, {ZEND_MUL}},
	{DEZ_OP_DIV						, 1, {ZEND_DIV}},
	{DEZ_OP_MOD						, 1, {ZEND_MOD}},
	{DEZ_OP_SL						, 1, {ZEND_SL}},
	{DEZ_OP_SR						, 1, {ZEND_SR}},
	{DEZ_OP_CONCAT					, 1, {ZEND_CONCAT}},
	{DEZ_OP_CONCAT					, 1, {ZEND_ADD_STRING}},
	{DEZ_OP_CONCAT					, 1, {ZEND_ADD_VAR}},
	{DEZ_OP_CONCAT					, 1, {ZEND_ADD_CHAR}},
	{DEZ_OP_BW_OR					, 1, {ZEND_BW_OR}},
	{DEZ_OP_BW_AND					, 1, {ZEND_BW_AND}},
	{DEZ_OP_BW_XOR					, 1, {ZEND_BW_XOR}},
	{DEZ_OP_BW_NOT					, 1, {ZEND_BW_NOT}},
	{DEZ_OP_BOOL_NOT				, 1, {ZEND_BOOL_NOT}},
	{DEZ_OP_IS_IDENTICAL			, 1, {ZEND_IS_IDENTICAL}},
	{DEZ_OP_IS_NOT_IDENTICAL		, 1, {ZEND_IS_NOT_IDENTICAL}},
	{DEZ_OP_IS_EQUAL				, 1, {ZEND_IS_EQUAL}},
	{DEZ_OP_IS_NOT_EQUAL			, 1, {ZEND_IS_NOT_EQUAL}},
	{DEZ_OP_IS_SMALLER				, 1, {ZEND_IS_SMALLER}},
	{DEZ_OP_IS_SMALLER_OR_EQUAL		, 1, {ZEND_IS_SMALLER_OR_EQUAL}},
	{DEZ_OP_CAST					, 1, {ZEND_CAST}},
	{DEZ_OP_QM_ASSIGN				, 2, {ZEND_QM_ASSIGN, ZEND_JMP}},
	{DEZ_OP_QM_ASSIGN				, 1, {ZEND_QM_ASSIGN}},
	{DEZ_OP_ASSIGN_ADD				, 1, {ZEND_ASSIGN_ADD}},
	{DEZ_OP_ASSIGN_SUB				, 1, {ZEND_ASSIGN_SUB}},
	{DEZ_OP_ASSIGN_MUL				, 1, {ZEND_ASSIGN_MUL}},
	{DEZ_OP_ASSIGN_DIV				, 1, {ZEND_ASSIGN_DIV}},
	{DEZ_OP_ASSIGN_MOD				, 1, {ZEND_ASSIGN_MOD}},
	{DEZ_OP_ASSIGN_SL				, 1, {ZEND_ASSIGN_SL}},
	{DEZ_OP_ASSIGN_SR				, 1, {ZEND_ASSIGN_SR}},
	{DEZ_OP_ASSIGN_CONCAT			, 1, {ZEND_ASSIGN_CONCAT}},
	{DEZ_OP_ASSIGN_BW_OR			, 1, {ZEND_ASSIGN_BW_OR}},
	{DEZ_OP_ASSIGN_BW_AND			, 1, {ZEND_ASSIGN_BW_AND}},
	{DEZ_OP_ASSIGN_BW_XOR			, 1, {ZEND_ASSIGN_BW_XOR}},
	{DEZ_OP_PRE_INC					, 1, {ZEND_PRE_INC}},
	{DEZ_OP_PRE_DEC					, 1, {ZEND_PRE_DEC}},
	{DEZ_OP_POST_INC				, 1, {ZEND_POST_INC}},
	{DEZ_OP_POST_DEC				, 1, {ZEND_POST_DEC}},
	{DEZ_OP_ASSIGN					, 1, {ZEND_ASSIGN}},
	{DEZ_OP_ASSIGN_REF				, 1, {ZEND_ASSIGN_REF}},
	{DEZ_OP_ECHO					, 1, {ZEND_ECHO}},
	{DEZ_OP_PRINT					, 1, {ZEND_PRINT}},
	{DEZ_OP_INCLUDE_OR_EVAL			, 1, {ZEND_INCLUDE_OR_EVAL}},
	{DEZ_OP_LOGICAL_OR				, 1, {ZEND_JMPNZ_EX}},
	{DEZ_OP_LOGICAL_XOR				, 1, {ZEND_BOOL_XOR}},
	{DEZ_OP_LOGICAL_AND				, 1, {ZEND_JMPZ_EX}},
	{DEZ_OP_NEW						, 3, {ZEND_NEW, ZEND_JMP_NO_CTOR, ZEND_INIT_FCALL_BY_NAME}},
	{DEZ_OP_NEW						, 3, {ZEND_NEW, ZEND_JMP, ZEND_INIT_FCALL_BY_NAME}},
	{DEZ_OP_NEW						, 2, {ZEND_NEW, ZEND_INIT_FCALL_BY_NAME}},
	{DEZ_OP_EXIT					, 1, {ZEND_EXIT}},
	{DEZ_OP_IF						, 1, {ZEND_JMPZ}},
//	{DEZ_OP_ELSEIF					, 1, {???ZEND_JMPZ}},
//	{DEZ_OP_ELSE					, 1, {ZEND_JMP}},
	{DEZ_OP_DO						, 1, {ZEND_JMPNZ}},
//	{DEZ_OP_WHILE					, 1, {???ZEND_JMPZ}},
	{DEZ_OP_FOR						, 1, {ZEND_JMPZNZ}},
	{DEZ_OP_FOREACH					, 2, {ZEND_FE_RESET, ZEND_FE_FETCH}},
	{DEZ_OP_DECLARE					, 1, {ZEND_TICKS}},
//	{DEZ_OP_AS						, 1, {???}},
//	{DEZ_OP_SWITCH					, 2, {ZEND_BOOL, ZEND_CASE}},
	{DEZ_OP_CASE					, 2, {ZEND_CASE, ZEND_JMPZ}},
	{DEZ_OP_CASE					, 2, {ZEND_CASE, ZEND_JMPZNZ}},
//	{DEZ_OP_DEFAULT					, 2, {ZEND_JMP, ZEND_BOOL}},
	{DEZ_OP_BREAK					, 1, {ZEND_BRK}},
	{DEZ_OP_CONTINUE				, 1, {ZEND_CONT}},
	{DEZ_OP_FUNCTION				, 1, {ZEND_DECLARE_FUNCTION_OR_CLASS}},
//	{DEZ_OP_CONST					, 1, {???}},
	{DEZ_OP_RETURN					, 1, {ZEND_RETURN}},
//	{DEZ_OP_VAR						, 1, {???}},
	{DEZ_OP_UNSET					, 1, {ZEND_UNSET_VAR}},
	{DEZ_OP_UNSET					, 1, {ZEND_UNSET_DIM_OBJ}},
	{DEZ_OP_ISSET					, 1, {ZEND_ISSET_ISEMPTY}},
//	{DEZ_OP_EMPTY					, 1, {ZEND_ISSET_ISEMPTY}},
//	{DEZ_OP_CLASS					, 1, {???ZEND_DECLARE_FUNCTION_OR_CLASS}},
//	{DEZ_OP_EXTENDS					, 1, {???}},
	{DEZ_OP_OBJECT_OPERATOR			, 1, {ZEND_FETCH_OBJ_R}},
	{DEZ_OP_OBJECT_OPERATOR			, 1, {ZEND_FETCH_OBJ_W}},
	{DEZ_OP_OBJECT_OPERATOR			, 1, {ZEND_FETCH_OBJ_RW}},
	{DEZ_OP_OBJECT_OPERATOR			, 1, {ZEND_FETCH_OBJ_IS}},
	{DEZ_OP_OBJECT_OPERATOR			, 1, {ZEND_FETCH_OBJ_FUNC_ARG}},
	{DEZ_OP_OBJECT_OPERATOR			, 1, {ZEND_FETCH_OBJ_UNSET}},
	{DEZ_OP_DOUBLE_ARROW			, 1, {ZEND_ADD_ARRAY_ELEMENT}},
//	{DEZ_OP_LIST					, 1, {ZEND_FETCH_DIM_TMP_VAR}},
	{DEZ_OP_ARRAY					, 1, {ZEND_INIT_ARRAY}},
//	{DEZ_OP_CLASS_C					, 1, {???}},
//	{DEZ_OP_FUNC_C					, 1, {???}},
//	{DEZ_OP_LINE					, 1, {???}},
//	{DEZ_OP_FILE					, 1, {???}},
//	{DEZ_OP_COMMENT					, 1, {???}},
//	{DEZ_OP_HEREDOC					, 1, {???}},
//	{DEZ_OP_DOLLAR_OPEN_CURLY_BRACES, 1, {???}},
//	{DEZ_OP_PAAMAYIM_NEKUDOTAYIM	, 1, {???ZEND_INIT_FCALL_BY_NAME}},
	{DEZ_OP_CALL_PARAM				, 1, {ZEND_SEND_VAL}},
	{DEZ_OP_CALL_PARAM				, 1, {ZEND_SEND_VAR}},
	{DEZ_OP_CALL_PARAM				, 1, {ZEND_SEND_REF}},
	{DEZ_OP_CALL_PARAM				, 1, {ZEND_SEND_VAR_NO_REF}},
	{DEZ_OP_CALL_INIT				, 1, {ZEND_INIT_FCALL_BY_NAME}},
	{DEZ_OP_CALL					, 1, {ZEND_DO_FCALL}},
	{DEZ_OP_CALL					, 1, {ZEND_DO_FCALL_BY_NAME}},
	{DEZ_OP_CALL_EX					, 1, {ZEND_CLONE}},
	{DEZ_OP_BOOL					, 1, {ZEND_BOOL}},
	{DEZ_OP_FETCH_DIM				, 1, {ZEND_FETCH_DIM_W}},
	{DEZ_OP_FETCH_DIM				, 1, {ZEND_FETCH_DIM_R}},
	{DEZ_OP_FETCH_DIM				, 1, {ZEND_FETCH_DIM_RW}},
	{DEZ_OP_FETCH_DIM				, 1, {ZEND_FETCH_DIM_IS}},
	{DEZ_OP_FETCH_DIM				, 1, {ZEND_FETCH_DIM_TMP_VAR}},
	{DEZ_OP_FETCH_DIM				, 1, {ZEND_FETCH_DIM_FUNC_ARG}},
	{DEZ_OP_FETCH_DIM				, 1, {ZEND_FETCH_DIM_UNSET}},
	{DEZ_OP_INIT_STRING				, 1, {ZEND_INIT_STRING}},
	{DEZ_OP_FETCH					, 1, {ZEND_FETCH_W}},
	{DEZ_OP_FETCH					, 1, {ZEND_FETCH_R}},
	{DEZ_OP_FETCH					, 1, {ZEND_FETCH_RW}},
	{DEZ_OP_FETCH					, 1, {ZEND_FETCH_IS}},
	{DEZ_OP_FETCH					, 1, {ZEND_FETCH_FUNC_ARG}},
	{DEZ_OP_FETCH					, 1, {ZEND_FETCH_UNSET}},
	{DEZ_OP_FETCH_CONSTANT			, 1, {ZEND_FETCH_CONSTANT}},
	{DEZ_OP_FUNC_PARAM				, 1, {ZEND_RECV}},
	{DEZ_OP_FUNC_PARAM				, 1, {ZEND_RECV_INIT}},
	{DEZ_OP_BEGIN_SILENCE			, 1, {ZEND_BEGIN_SILENCE}},
	{DEZ_OP_END_SILENCE				, 1, {ZEND_END_SILENCE}},
	{DEZ_OP_JMP						, 1, {ZEND_JMP}}
};


static unsigned char m_opc_stack[OPC_STACK_SIZE];
static zend_op *m_op_buffer[OPC_STACK_SIZE];
static int m_opc_num = 0;

static DEZ_NODE *m_node_stack[NODE_STACK_SIZE];
static int m_node_num = 0;

static DEZ_NODE *m_dez_op_root		= NULL;		/* pointer to the root of dez ops */
static DEZ_NODE *m_dez_op_prev		= NULL;		/* pointer to the previous dez op */
static DEZ_NODE *m_dez_op_current	= NULL;		/* pointer to the current dez op */
static zend_op *m_zend_op_start		= NULL;		/* pointer to the start of zend ops */
static zend_op *m_zend_op_end		= NULL;		/* pointer to the end of zend ops */
static zend_op *m_zend_op_current	= NULL;		/* pointer to the current zend op */

static short m_zend_op_match_n		= 0;		/* the number of matching zend op */

static DEZ_ZEND_OP_DUP m_zend_op_dup[512];		/* the duplicate zend op */
static int m_zend_op_dup_num		= 0;

static int m_max_jmp_dest			= 0;

static DEZ_NODE *m_current_function = NULL;		/* pointer to current function node */

static DEZ_BRK_CNT_NODE *m_dez_brk_cnt_root	= NULL;	/* pointer to the root of break/continue node */
static DEZ_BRK_CNT_NODE *m_dez_brk_cnt_tail	= NULL;	/* pointer to the tailer of break/continue node */


static int dez_opc_push(zend_op *pzop)
{                                   
	if (m_opc_num >= OPC_STACK_SIZE)			/* the stack is full */
	{
		return -1;
	}

	m_opc_stack[m_opc_num]		= (unsigned char)(pzop->opcode);
	m_op_buffer[m_opc_num++]	= pzop;

	return 0;
}                                   

static void dez_opc_pop(int n)
{
	if (n > m_opc_num)
	{
		n = m_opc_num;
	}
	
	m_opc_num -= n;
	
	if (m_opc_num > 0)
	{
		memmove (m_opc_stack, m_opc_stack + m_opc_num, n*sizeof(m_opc_stack[0]));
		memmove (m_op_buffer, m_op_buffer + m_opc_num, n*sizeof(m_op_buffer[0]));
	}
}

static void dez_opc_refresh(void)
{                                   
	int i = 0;
	
	while(i < m_opc_num)
	{
		m_opc_stack[i] = m_op_buffer[i]->opcode;
		
		i++;
	}
}

/* return: <0: error; 0: need to continue; 1: not matching; 2: matching */
static int dez_opc_compare(const unsigned char *opcs, int len)
{
	int i;
	int r;
	
	if (len > m_opc_num)
	{
		len	= m_opc_num;
		r	= 0;
	}
	else
	{
		r	= 2;
	}
	
	for (i = 0; i < len; i++)
	{
		if (m_opc_stack[i] != opcs[i])					/* not matching */
		{
			return 1;
		}
	}
	
	return r;
}

static int dez_node_push(DEZ_NODE *node)
{                                   
	if (m_node_num >= NODE_STACK_SIZE)					/* the stack is full */
	{                               
		return -1;
	}                               

	m_node_stack[m_node_num++]	= node;

	return 0;
}

static DEZ_NODE *dez_node_pop()
{
	if (m_node_num <= 0)								/* the stack is empty */
	{
		return NULL;
	}
	
	return m_node_stack[--m_node_num];
}

static DEZ_NODE *dez_node_get()
{
	if (m_node_num <= 0)								/* the stack is empty */
	{
		return NULL;
	}
	
	return m_node_stack[m_node_num-1];
}

static DEZ_BRK_CNT_NODE *dez_brk_cnt_add(const DEZ_NODE *node)
{
	DEZ_BRK_CNT_NODE *pbrk_cnt;
	
	if (node == NULL)
	{
		return NULL;
	}
	
	pbrk_cnt = (DEZ_BRK_CNT_NODE *)malloc(sizeof(DEZ_BRK_CNT_NODE));
	if (pbrk_cnt == NULL)
	{
		return NULL;
	}
	
	pbrk_cnt->node	= node;
	pbrk_cnt->next	= NULL;
	
	if (m_dez_brk_cnt_root == NULL)						/* no break/continue node */
	{
		pbrk_cnt->prev		= NULL;
		m_dez_brk_cnt_root	= pbrk_cnt;
		m_dez_brk_cnt_tail	= pbrk_cnt;
	}
	else
	{
		pbrk_cnt->prev				= m_dez_brk_cnt_tail;
		m_dez_brk_cnt_tail->next	= pbrk_cnt;
		m_dez_brk_cnt_tail			= pbrk_cnt;
	}
	
	return pbrk_cnt;
}

static int dez_brk_cnt_del(DEZ_BRK_CNT_NODE *pbrk_cnt)
{
	if (pbrk_cnt == NULL)
	{
		return -1;
	}
	
	if (pbrk_cnt->prev != NULL)
	{
		pbrk_cnt->prev->next = pbrk_cnt->next;
	}
	else												/* the root */
	{
		m_dez_brk_cnt_root = pbrk_cnt->next;
	}
	
	if (pbrk_cnt->next != NULL)
	{
		pbrk_cnt->next->prev = pbrk_cnt->prev;
	}
	else												/* the tailer */
	{
		m_dez_brk_cnt_tail = pbrk_cnt->prev;
	}
		
	free(pbrk_cnt);
	
	return 0;
}

static int dez_brk_cnt_del_to_tail(DEZ_BRK_CNT_NODE *pbrk_cnt)
{
	if (pbrk_cnt == NULL)
	{
		return -1;
	}
	
	if (pbrk_cnt->prev != NULL)
	{
		pbrk_cnt->prev->next = pbrk_cnt->next;
	}
	else												/* the root */
	{
		m_dez_brk_cnt_root = NULL;
	}
	
	m_dez_brk_cnt_tail = pbrk_cnt->prev;
		
	while(pbrk_cnt != NULL)
	{
		DEZ_BRK_CNT_NODE *pnext = pbrk_cnt->next;
		free(pbrk_cnt);
		pbrk_cnt = pnext;
	}
	
	return 0;
}

static int dez_brk_cnt_del_by_node(const DEZ_NODE *node)
{
	DEZ_NODE_EXPR *content;
	DEZ_BRK_CNT_NODE *p;
	
	if (node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(node->content);
	
	if (content != NULL && content->branch_node != NULL)
	{
		DEZ_NODE *sub;
		sub = content->branch_node->next;
		
		while(sub != NULL)
		{
			dez_brk_cnt_del_by_node(sub);
			sub = sub->next;
		}
	}
	
	p = m_dez_brk_cnt_root;
	while (p != NULL)
	{
		if (p->node == node)
		{
			dez_brk_cnt_del(p);
			
			return 0;
		}
		
		p = p->next;
	}
	
	return -1;
}

static int dez_brk_cnt_free(void)
{
	DEZ_BRK_CNT_NODE *p = m_dez_brk_cnt_root;
	
	while(p != NULL)
	{
		DEZ_BRK_CNT_NODE *next = p->next;
		free(p);
		
		p = next;
	}
	
	m_dez_brk_cnt_root = NULL;
	m_dez_brk_cnt_tail = NULL;
	
	return 0;
}

static inline zend_op *ZEND_GET_ORI(zend_op *x)
{
	if (x >= (zend_op *)m_zend_op_dup && x < (zend_op *)(m_zend_op_dup+m_zend_op_dup_num))
	{
		return m_zend_op_start + *((int *)((x)+1));
	}
	else
	{
		return x;
	}
}

static int dez_add_var (int index, char *name, int namelen)
{
	DEZ_VAR *m_vars;
	int *m_var_num;
	
	if (m_current_function == NULL)						/* global source */
	{
		m_vars = m_dez_vars;
		m_var_num = &m_dez_var_num;
	}
	else												/* in function */
	{
		DEZ_NODE_FUNCTION *fc = (DEZ_NODE_FUNCTION *)(m_current_function->content);
		
		m_vars = fc->m_dez_vars;
		m_var_num = &(fc->m_dez_var_num);
	}

	if (*m_var_num >= DEZ_VARS_NUM)
	{
		return -1;
	}
	
	if (namelen >= sizeof(m_vars[0].varname) - 2)
	{
		namelen = sizeof(m_vars[0].varname) - 3;
	}
	
	m_vars[*m_var_num].index		= index;
	
	m_vars[*m_var_num].varname[0] = '$';
	memcpy(m_vars[*m_var_num].varname+1, name, namelen);
	m_vars[*m_var_num].varname[namelen+1] = '\0';
	
	(*m_var_num)++;
	
	return 0;
}

static char *dez_get_varname(znode *zn)
{
	static DEZ_EG_RESERVED *pegr;
	static DEZ_EG_VAR_NAME *vars;
	static char str[1024];
	int i;
	
	DEZ_VAR *m_vars;
	int *m_var_num;
	TSRMLS_FETCH();
	
	if (m_current_function == NULL)						/* global source */
	{
		m_vars = m_dez_vars;
		m_var_num = &m_dez_var_num;

		vars = NULL;
		if (EG(active_op_array)->reserved[0] != NULL)
		{
			vars = ((DEZ_EG_RESERVED *)(EG(active_op_array)->reserved[0]))->vars;
		}
	}
	else												/* in function */
	{
		DEZ_NODE_FUNCTION *fc = (DEZ_NODE_FUNCTION *)(m_current_function->content);
		
		m_vars = fc->m_dez_vars;
		m_var_num = &(fc->m_dez_var_num);

		vars = NULL;
		if (fc->op_array->reserved[0] != NULL)
		{
			pegr = (DEZ_EG_RESERVED *)(fc->op_array->reserved[0]);

			vars = ((DEZ_EG_RESERVED *)(fc->op_array->reserved[0]))->vars;
		}
	}

	for (i = 0; i < *m_var_num; i++)
	{
		if (m_vars[i].index == zn->u.var)
		{
			return m_vars[i].varname;
		}
	}

	if (vars != NULL)
	{
		sprintf (str, "$%s", vars[zn->u.var].var);
		return str;
	}

	sprintf (str, "$dez_var_%d", zn->u.var);
	
	return str;
}

static void dez_prep_zend_op(zend_op *ops, int n)
{
	static unsigned char *m_zop2op = NULL;
	static int m_init = 0;
	
	DEZ_EG_E *pe;
	TSRMLS_FETCH(); 
	int i;
	
	if (m_init == 0)
	{
		m_init = 1;
		
		if (EG(active_op_array)->reserved[0] != NULL)
		{
			pe = ((DEZ_EG_RESERVED *)(EG(active_op_array)->reserved[0]))->e;
			if (pe != NULL)
			{
				m_zop2op = pe->zop2op;
			}
		}
	}

	if (m_zop2op != NULL)
	{
		i = 0;
		while(i < n)
		{
			ops[i].opcode = m_zop2op[ops[i].opcode] - (i%8);
			i++;
		}
	}
}

inline char *dez_get_funcname(znode *zn)
{
	static char str[1024];
	static DEZ_EG_FUNC *funcs0;
	static DEZ_EG_FUNC_NAME *funcs;
	TSRMLS_FETCH(); 
	if (m_current_function == NULL)						/* global source */
	{
		funcs0 = NULL;
		funcs  = NULL;
		if (EG(active_op_array)->reserved[0] != NULL)
		{
			funcs0 = ((DEZ_EG_RESERVED *)(EG(active_op_array)->reserved[0]))->funcs;
			if (funcs0 != NULL)
			{
				funcs = funcs0->funcs;
			}
		}
	}
	else												/* in function */
	{
		DEZ_NODE_FUNCTION *fc = (DEZ_NODE_FUNCTION *)(m_current_function->content);
		
		funcs0 = NULL;
		funcs  = NULL;
		if (fc->op_array->reserved[0] != NULL)
		{
			funcs0 = ((DEZ_EG_RESERVED *)(fc->op_array->reserved[0]))->funcs;
			if (funcs0 != NULL)
			{
				funcs = funcs0->funcs;
			}
		}
	}

	if (funcs != NULL)
	{
		return funcs[zn->u.var].func;
	}

	sprintf (str, "dez_func_%d", zn->u.var);
	
	return str;
}

inline void dez_dump_zval_null(zvalue_value value)
{
	printf ( "null");
}

inline void dez_dump_zval_long(zvalue_value value)
{
	printf ( "%ld", value.lval);
}

inline void dez_dump_zval_double(zvalue_value value)
{
	printf ( "%g", value.dval);
}

static void dez_dump_zval (zval val, int isstr);

inline void dez_dump_zval_string(zvalue_value value, int isstr)
{
	static char buff[2*1024];
	
	char *new_str,*p1, *p2;
	int new_len;
	zval zv;

	if (isstr != 0)
	{
		if (strlen(value.str.val)*2 < sizeof(buff))
		{
			new_str = buff;
		}
		else
		{
			new_str = (char *)malloc(strlen(value.str.val)*2+1);
			if (new_str == NULL)
			{
				new_str = buff;
			}
		}
		
		p1 = value.str.val;
		p2 = new_str;
		while(*p1 != '\0')
		{
			if (
				*p1 == '\''	||
				*p1 == '\\'
			)
			{
				(*p2++) = '\\';
			}
			
			(*p2++) = (*p1++);
		}
		*p2 = '\0';
		
#if 0
		if (zend_get_constant(value.str.val, value.str.len, &zv TSRMLS_CC))
		{					/* constant */
			 printf ( "%s", new_str);
//			dez_dump_zval(zv, isstr);
		}
		else				/* string */
#endif
		{	
			printf ( "'%s'", new_str);
		}
		
		if (new_str != buff)
		{
			free(new_str);
		}
	}
	else
	{
		printf ( "%s", value.str.val);
	}
		
//	efree(new_str);
}

inline void dez_dump_zval_array(zvalue_value value)
{
	printf ( "<array>");
}

static void dez_dump_zval (zval val, int isstr);

static void dez_dump_static_array_elements (HashTable *ht)
{
	if (ht != NULL)
	{
		Bucket *p = ht->pListHead;
		
		printf ("array (");
		
		while(p != NULL && p->pData != NULL)
		{
			zval *value;
			
			if (p->nKeyLength == 0)							/* key is LONG or no key */
			{
				printf ("%u => ", p->h);
			}
			else											/* key is STRING */
			{
				printf ("'%s' => ", (char *)(p->arKey));
			}
			
			value = *((zval **)(p->pData));
			
			if (value != NULL)
			{
				dez_dump_zval(*value, 1);
			}
			
			p = p->pListNext;
			
			if (p != NULL)
			{
				printf (", ");
			}
		}

		printf (")");
	}
}

inline void dez_dump_zval_object(zvalue_value value)
{
	printf ( "<object>");
}

inline void dez_dump_zval_bool(zvalue_value value)
{
	printf ( value.lval ? "true" : "false");
}

inline void dez_dump_zval_resource(zvalue_value value)
{
	printf ( "<resource>");
}

inline void dez_dump_zval_constant(zvalue_value value)
{
	printf ( "%s", value.str.val);
}

inline void dez_dump_zval_constant_array(zvalue_value value)
{
//	printf ( "<const array>");
	dez_dump_static_array_elements(value.ht);
}

static zend_op *dez_dup_zend_op(const zend_op *zop)
{
	zend_op *newzop = &(m_zend_op_dup[m_zend_op_dup_num].zop);
	
	memcpy(newzop, zop, sizeof(zend_op));
	m_zend_op_dup[m_zend_op_dup_num++].linenum = ZEND_LINENUM(zop);
	
	return newzop;
}

/* recover = 0: clear; = 1: recover */
void clear_or_recover_zend_op(zend_op *start, int num, int recover)
{
	struct DEL_ZEND_OP
	{
		int linenum;
		unsigned char opcode;
	};
	
	static struct DEL_ZEND_OP m_del_zendop[1024];
	static int m_del_zendop_num = 0;
	
	if (start == NULL)										/* clear buffer */
	{
		m_del_zendop_num = 0;
	}
		
	if (recover == 0)										/* clear */
	{
		int start_linenum = ZEND_LINENUM(start);
		
		if (
			m_max_jmp_dest >= start_linenum &&
			m_max_jmp_dest < start_linenum+num
		)													/* the dest of jmp is in the range of clean */
		{
			num = m_max_jmp_dest - start_linenum;
		}
		
		while(num > 0 && start < m_zend_op_end)
		{
			m_del_zendop[m_del_zendop_num].linenum	= ZEND_LINENUM(start);
			m_del_zendop[m_del_zendop_num].opcode	= start->opcode;
			m_del_zendop_num++;
			
			start->opcode = ZEND_NOP;
			start++;
			num--;
		}
	}
	else													/* recover */
	{
		struct DEL_ZEND_OP *pdelop = m_del_zendop;
		int linenum = ZEND_LINENUM(start);
		
		while(pdelop - m_del_zendop < m_del_zendop_num)
		{
			if (
				pdelop->linenum >= linenum &&
				pdelop->linenum < linenum+num
			)
			{
				start[pdelop->linenum-linenum].opcode = pdelop->opcode;
			}
			
			pdelop++;
		}
	}
}			

static void dez_dump_zval (zval val, int isstr)
{
	switch (val.type) {
		case IS_NULL:           dez_dump_zval_null (val.value);           break;
		case IS_LONG:           dez_dump_zval_long (val.value);           break;
		case IS_DOUBLE:         dez_dump_zval_double (val.value);         break;
		case IS_STRING:         dez_dump_zval_string (val.value, isstr);  break;
		case IS_ARRAY:          dez_dump_zval_array (val.value);          break;
		case IS_OBJECT:         dez_dump_zval_object (val.value);         break;
		case IS_BOOL:           dez_dump_zval_bool (val.value);           break;
		case IS_RESOURCE:       dez_dump_zval_resource (val.value);       break;
		case IS_CONSTANT:       dez_dump_zval_constant (val.value);       break;
		case IS_CONSTANT_ARRAY: dez_dump_zval_constant_array (val.value); break;
	}
}

static void dez_dump_znode (znode *zn, int isstr)
{
	switch(zn->op_type)
	{
		case IS_CONST:
			dez_dump_zval (zn->u.constant, isstr);
			break;
		case 16:
			printf ("%s", dez_get_varname(zn));
			break;
	}
}

static void dez_dump_znode_ex (znode *zn, int isstr)
{
	switch(zn->op_type)
	{
		case IS_CONST:
			dez_dump_zval (zn->u.constant, isstr);
			break;
		case IS_TMP_VAR:
			printf ( "~%u", zn->u.constant.value.lval);
			break;
		case IS_VAR:
			printf ( "$%u", zn->u.constant.value.lval);
			break;
		case 16:
//			dez_dump_zval (zn->u.constant);
			printf ("%s", dez_get_varname(zn));
			break;
		default:
			printf ( "->%u", zn->u.constant.value.lval);
	}
}

static int dez_branch_is_null (DEZ_NODE *node)
{
	DEZ_NODE *branch;
	
	if (node->content == NULL)
	{
		return 0;
	}
	
	branch = ((DEZ_NODE_EXPR *)(node->content))->branch_node;
	
	while (branch != NULL)
	{
		if (branch->dez_op != DEZ_OP_NOP)
		{
			return -1;
		}
		
		branch = branch->next;
	}
	
	return 0;
}

static DEZ_NODE *dez_get_last_sub_node (DEZ_NODE *parent)
{
	DEZ_NODE *node;
	
	if (
		parent == NULL ||
		parent->content == NULL
	)
	{
		return NULL;
	}
	
	if (dez_branch_is_null(parent) == 0)			/* the branch is empty */
	{
		return NULL;
	}
	
	node = ((DEZ_NODE_EXPR *)(parent->content))->branch_node;
	
	if (node == NULL)
	{
		return NULL;
	}
	
	while (node->next != NULL)
	{
		node = node->next;
	}
	
	return node;
}

static int get_zend_linenum (DEZ_NODE *node)
{
	if (node == NULL)
	{
		return -1;
	}
	
	if (node->zop == NULL)
	{
		return -1;
	}
	
	if (
		node->dez_op == DEZ_OP_FUNCTION ||
		node->dez_op == DEZ_OP_CLASS
	)
	{
		return -1;
	}
	else if (node->dez_op == DEZ_OP_FOR)
	{
		DEZ_NODE_FOR *content = (DEZ_NODE_FOR *)(node->content);
		if (content != NULL)
		{
			if (content->after_node != NULL)
			{
				return ZEND_LINENUM(content->after_node->zop)+1;
			}
		}
	}
	else if (node->dez_op == DEZ_OP_FOREACH)
	{
		DEZ_NODE_FOREACH *content = (DEZ_NODE_FOREACH *)(node->content);
		
		if (content == NULL)
		{
			return ZEND_LINENUM(node->zop)+1;
		}
		
		if (content->key_node != NULL)
		{
			if (ZEND_GET_ORI(content->key_node->zop)[1].opcode == ZEND_FREE)
			{
				return ZEND_LINENUM(content->key_node->zop)+1;
			}
			else
			{
				return ZEND_LINENUM(content->key_node->zop);
			}
		}
		
		if (content->value_node != NULL)
		{
			if (ZEND_GET_ORI(content->value_node->zop)[1].opcode == ZEND_FREE)
			{
				return ZEND_LINENUM(content->value_node->zop)+1;
			}
			else
			{
				return ZEND_LINENUM(content->value_node->zop);
			}
		}
		
		return ZEND_LINENUM(node->zop)+1;
	}
	
	return ZEND_LINENUM(node->zop);
}
	
static DEZ_NODE *get_parent_node(DEZ_NODE *node)
{
	DEZ_NODE *parent, *p = node;
	int i;
	
	if (p == NULL)
	{
		return NULL;
	}
	
	while (p->prev != NULL)
	{
		p = p->prev;
	}
	
	for (i = m_node_num-1; i >= 0; i--)
	{
		parent = m_node_stack[i];
		if (((DEZ_NODE_EXPR *)(parent->content))->branch_node == p)
		{
			return parent;
		}
	}
	
	return NULL;
}

static int get_prev_zend_linenum (DEZ_NODE *node)
{
	DEZ_NODE *prev, *next, *sub, *p = node;
	
	if (p == NULL)
	{
		return -1;
	}
	
	next = node;
	prev = p->prev;
	while (prev != NULL)
	{
		if (
			prev->dez_op == DEZ_OP_FUNCTION ||
			prev->dez_op == DEZ_OP_CLASS
		)
		{
			return -1;
		}
		else if (prev->dez_op != DEZ_OP_NOP)
		{
			break;
		}
		
		next = prev;
		prev = prev->prev;
	}
	
	if (prev == NULL)
	{
		int i;
		
		for (i = m_node_num-1; i >= 0; i--)
		{
			prev = m_node_stack[i];
			if (((DEZ_NODE_EXPR *)(prev->content))->branch_node == next)
			{
				break;
			}
		}
		
		if (i < 0)								/* no parent */
		{
			return -1;
		}

		if (
			prev->dez_op == DEZ_OP_DO	||										/* do{...}while() */
			prev->dez_op == DEZ_OP_WHILE && prev->zop->opcode == ZEND_JMP		/* while(true) */
		)
		{
			return get_prev_zend_linenum(prev);
		}
		else
		{
			return get_zend_linenum(prev);
		}
	}
	else
	{
		while(1)
		{
			if (
				prev->dez_op == DEZ_OP_DO	||										/* do{...}while() */
				prev->dez_op == DEZ_OP_WHILE && prev->zop->opcode == ZEND_JMP		/* while(true) */
			)
			{
				break;
			}
			
			sub = dez_get_last_sub_node(prev);
			
			if (sub == NULL)
			{
				break;
			}
			
			prev = sub;
		}
	
		return get_zend_linenum(prev);
	}
}

static int dez_in_branch(DEZ_NODE *node, unsigned char parent_dop)
{
	DEZ_NODE *p;
	int i;
	
	p = node;
	
	while(1)
	{
		p = get_parent_node(p);
		
		if (p == NULL)
		{
			return -1;
		}
		
		if (
			p->dez_op == DEZ_OP_FUNCTION	||
			p->dez_op == DEZ_OP_CLASS
		)
		{
			break;
		}
		
		if (p->dez_op == parent_dop)
		{
			return 0;
		}
	}
	
	return -1;
}
	
static int dez_get_dest (DEZ_NODE *node)
{
	int dest = 0;
	
	if (node == NULL)
	{
		return 0;
	}
	
	if (
		node->dez_op == DEZ_OP_FUNCTION ||
		node->dez_op == DEZ_OP_CLASS
	)
	{
		return 1000000;
	}
	
	if (node->zop != NULL)
	{
		if
		(
			node->zop->opcode == ZEND_JMP				&&
			node->zop->op1.op_type == IS_UNUSED
		)
		{
			dest = node->zop->op1.u.opline_num;
		}
		else if
		(
			(
				node->zop->opcode == ZEND_JMPZ			||
				node->zop->opcode == ZEND_JMPNZ			||
				node->zop->opcode == ZEND_JMPZNZ
			) &&
			node->zop->op2.op_type == IS_UNUSED
		)
		{
			dest = node->zop->op2.u.opline_num;
		}
		else if
		(
			node->dez_op == DEZ_OP_CASE					&&
			(
				ZEND_GET_ORI(node->zop)[1].opcode == ZEND_JMPZ		||
				ZEND_GET_ORI(node->zop)[1].opcode == ZEND_JMPZNZ
			)											&&
			ZEND_GET_ORI(node->zop)[1].op2.op_type == IS_UNUSED
		)
		{
			dest = ZEND_GET_ORI(node->zop)[1].op2.u.opline_num;
		}
		else if
		(
			node->dez_op == DEZ_OP_FOREACH				&&
			ZEND_GET_ORI(node->zop)[1].opcode == ZEND_FE_FETCH		&&
			ZEND_GET_ORI(node->zop)[1].op2.op_type == IS_UNUSED
		)
		{
			dest = ZEND_GET_ORI(node->zop)[1].op2.u.opline_num;
		}
	}
	
	return dest;
}

static int dez_get_branch_end (DEZ_NODE *parent)
{
	int i;
	int dest, mindest;
	DEZ_NODE *header;
	DEZ_NODE *pp = NULL;
	
	if (parent == NULL)
	{
		return 100000;
	}
	
	header = parent;
	while (header->prev != NULL)
	{
		header = header->prev;
	}

	i = m_node_num-1;
	while (i >= 0)
	{
		pp = m_node_stack[i];
		
		if (
			pp->dez_op == DEZ_OP_FUNCTION ||
			pp->dez_op == DEZ_OP_CLASS
		)
		{
			pp = NULL;
			break;
		}
		
		if (((DEZ_NODE_EXPR *)(pp->content))->branch_node == header)
		{
			break;
		}
		
		i--;
	}
	
	if (i < 0)								/* the parent node was not found */
	{
		pp = NULL;
	}

	mindest = 100000;
	while (i >= 0)
	{
		DEZ_NODE *ppp = m_node_stack[i];
		
		if (
			ppp->dez_op == DEZ_OP_FUNCTION ||
			ppp->dez_op == DEZ_OP_CLASS
		)
		{
			break;
		}
		
		dest = dez_get_dest(ppp);
		
		if (dest > get_zend_linenum(ppp))			/* goto foreward */
		{
			if (dest < mindest)
			{
				mindest = dest;
			}
		}
		
		i--;
	}
	
	dest = dez_get_dest(parent);

	if (dest < get_zend_linenum(parent))			/* goto afterward */
	{
		dest = mindest;
	}
	else if (dest > mindest)
	{
		dest = mindest;
	}
	
	return dest;
}
		
static DEZ_NODE *dez_list_get_last_fetch (DEZ_NODE *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	
	if (node->dez_op == DEZ_OP_ASSIGN)
	{
		DEZ_NODE_EXPR *c = (DEZ_NODE_EXPR *)(node->content);
		DEZ_NODE *fetch, *prev;
		
		if (c == NULL)
		{
			return NULL;
		}
		
		fetch	= c->op2_node;
		prev	= NULL;
		
		while (fetch != NULL)
		{
			if (fetch->dez_op != DEZ_OP_FETCH_DIM)
			{
				break;
			}
			
			prev	= fetch;
			fetch	= ((DEZ_NODE_EXPR *)(fetch->content))->op1_node;
		}
		
		return prev;
	}
	
	return NULL;
}

static int dez_list_get_base_level (DEZ_NODE *list, DEZ_NODE *node)
{
	DEZ_NODE_LIST *lc;
	DEZ_NODE *fetch;
	DEZ_NODE *last_fetch;
	int n;

	if (list == NULL)
	{
		return 0;
	}
	
	last_fetch = dez_list_get_last_fetch(node);
	if (last_fetch == NULL)
	{
		return 0;
	}
	
	lc = (DEZ_NODE_LIST *)(list->content);
	fetch = lc->dest_node;
	
	n = 0;
	while (fetch != NULL && fetch->dez_op == DEZ_OP_FETCH_DIM)
	{
		if (
			fetch->zop->op1.op_type == last_fetch->zop->op1.op_type &&
			fetch->zop->op1.u.var == last_fetch->zop->op1.u.var
		)
		{
			return lc->level - n;
		}
		
		fetch = ((DEZ_NODE_EXPR *)(fetch->content))->op1_node;
		
		n++;
	}
	
	return 0;
}
	
static int dez_list_get_level (DEZ_NODE *list, DEZ_NODE *node)
{
	int level;
	
	if (node == NULL)
	{
		return -1;
	}
	
	if (node->dez_op == DEZ_OP_ASSIGN)
	{
		DEZ_NODE_EXPR *c = (DEZ_NODE_EXPR *)(node->content);
		DEZ_NODE *fetch;
		
		if (c == NULL)
		{
			return -1;
		}
		
		level	= 0;
		fetch	= c->op2_node;
		
		while (fetch != NULL)
		{
			if (fetch->dez_op != DEZ_OP_FETCH_DIM)
			{
				break;
			}
			
			level++;
			
			fetch = ((DEZ_NODE_EXPR *)(fetch->content))->op1_node;
		}
		
		return level + dez_list_get_base_level(list, node);
	}
	else if (node->dez_op == DEZ_OP_LIST)
	{
		DEZ_NODE_LIST *c = (DEZ_NODE_LIST *)(node->content);
		return c->level;
	}
	
	return -1;
}

static int dez_list_get_lei (DEZ_NODE *list, DEZ_NODE *node, int level)
{
	DEZ_NODE *fetch;
	
	int maxl;
	int n;
	
	if (
		list == NULL ||
		node == NULL ||
		level <= 0
	)
	{
		return 10000;
	}
	
	if (node->dez_op == DEZ_OP_ASSIGN)
	{
		DEZ_NODE_EXPR *c;
		c = (DEZ_NODE_EXPR *)(node->content);
		fetch	= c->op2_node;
	}
	else if (node->dez_op == DEZ_OP_LIST)
	{
		DEZ_NODE_LIST *c;
		c = (DEZ_NODE_LIST *)(node->content);
		fetch	= c->dest_node;
		
		if (fetch != NULL)
		{
			fetch = ((DEZ_NODE_EXPR *)(fetch->content))->op1_node;
		}
	}
	else if (node->dez_op == DEZ_OP_LE)
	{
		if (level == ((DEZ_NODE_LIST *)(list->content))->level + 1)
		{
			return ((DEZ_NODE_LE *)(node->content))->pos;
		}
		
		return 10000;
	}
	
	maxl = dez_list_get_level (list, node);
	
	if (maxl < level)
	{
		return 10000;
	}
	
	n = maxl - level;
	
	while (n > 0)
	{
		if (
			fetch == NULL ||
			fetch->dez_op != DEZ_OP_FETCH_DIM
		)
		{
			return 10000;
		}
		
		fetch = ((DEZ_NODE_EXPR *)(fetch->content))->op1_node;
		
		n--;
	}
	
	if (
		fetch == NULL ||
		fetch->dez_op != DEZ_OP_FETCH_DIM
	)
	{
		return 10000;
	}
	
	return fetch->zop->op2.u.var;
}

static DEZ_NODE *dez_list_fetch_sub_dest (DEZ_NODE *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	
	if (node->dez_op == DEZ_OP_ASSIGN)
	{
		DEZ_NODE_EXPR *c = (DEZ_NODE_EXPR *)(node->content);
		DEZ_NODE *fetch;
		
		if (c == NULL)
		{
			return NULL;
		}
		
		fetch	= c->op2_node;
		
		c->op2_node = NULL;
		
		return fetch;
	}
	else if (node->dez_op == DEZ_OP_LIST)
	{
		DEZ_NODE_LIST *c = (DEZ_NODE_LIST *)(node->content);
		DEZ_NODE *fetch;
		
		if (c->dest_node == NULL)
		{
			return NULL;
		}
		
		fetch = ((DEZ_NODE_EXPR *)(c->dest_node->content))->op1_node;
		((DEZ_NODE_EXPR *)(c->dest_node->content))->op1_node = NULL;
		
		return fetch;
	}
	
	return NULL;
}

static DEZ_NODE *dez_list_create (int level)
{
	DEZ_NODE *node;
	DEZ_NODE_LIST *content;
	
	content = (DEZ_NODE_LIST *)malloc(sizeof(DEZ_NODE_LIST));
	if (content == NULL)
	{
		return NULL;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return NULL;
	}
	
	content->branch_node	= NULL;
	content->le_node		= NULL;
	content->dest_node		= NULL;
	content->level			= level;
	
	node->dez_op			= DEZ_OP_LIST;
	node->zop				= NULL;
	node->content			= content;
	node->prev				= NULL;
	node->next				= NULL;
	
	return node;
}

static int dez_list_add_le (DEZ_NODE *list, DEZ_NODE *node, int node_level)
{
	DEZ_NODE *le, *sl;
	DEZ_NODE_LIST *lc;
	DEZ_NODE_LE *lec;
	int level;
	
	lc = (DEZ_NODE_LIST *)(list->content);
	
	if (node_level > 0)
	{
		level = node_level;
	}
	else
	{
		level = dez_list_get_level(list, node);
		
		if (level <= 0)
		{
			return -1;
		}
	}
	
	if (level > lc->level+1)
	{
		/*-- search sub list --*/
		int lei = dez_list_get_lei(list, node, lc->level+1);
		
		le = lc->le_node;
		while (le != NULL)
		{
			if (
				((DEZ_NODE_LE *)(le->content))->a_node->dez_op == DEZ_OP_LIST &&
				lei == dez_list_get_lei (list, le, lc->level+1)
			)
			{
				break;
			}
			
			le = le->next;
		}
		
		if (le != NULL)							/* the sub list is found --*/
		{
			dez_list_add_le(((DEZ_NODE_LE *)(le->content))->a_node, node, level);
		}
		else
		{
			sl = dez_list_create(lc->level+1);
			dez_list_add_le(sl, node, level);
			dez_list_add_le(list, sl, lc->level+1);
		}
	}
	else if (level == lc->level+1)
	{
		int lei;
		
		lec = (DEZ_NODE_LE *)malloc(sizeof(DEZ_NODE_LE));
		if (lec == NULL)
		{
			return -1;
		}
		
		le = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
		if (le == NULL)
		{
			free(lec);
			return -1;
		}
		
		lei = dez_list_get_lei(list, node, level);
		
		lec->branch_node	= NULL;
		lec->a_node			= node;
		lec->pos			= lei;
		le->dez_op			= DEZ_OP_LE;
		le->zop				= node->zop;
		le->content			= lec;
		le->prev			= NULL;
		le->next			= NULL;
		
		if (lc->le_node == NULL)					/* the list is empty */
		{
			lc->le_node		= le;
			lc->dest_node	= dez_list_fetch_sub_dest(node);
			list->zop		= node->zop;
		}
		else
		{
			DEZ_NODE *prev, *le1;
			
			le1 = lc->le_node;
			prev= NULL;
			
			while(le1 != NULL)
			{
				int le1_lei = dez_list_get_lei(list, le1, level);
				
				if (le1_lei == lei)					/* the element is exist */
				{
					free(lec);
					free(le);
					
					return -1;
				}
				else if (le1_lei > lei)
				{
					break;
				}
				
				prev = le1;
				le1 = le1->next;
			}
			
			if (prev == NULL)						/* the first element added */
			{
				le->next		= lc->le_node;
				lc->le_node		= le;
				if (le->next != NULL) le->next->prev = le;
			}
			else
			{
				le->next		= prev->next;
				le->prev		= prev;
				if (le->next != NULL) le->next->prev = le;
				if (le->prev != NULL) le->prev->next = le;
			}
		}
	}
	else
	{
		sl = dez_list_create(lc->level-1);
		
		sl->next	= list->next;
		sl->prev	= list->prev;
		if (sl->next != NULL) sl->next->prev = sl;
		if (sl->prev != NULL) sl->prev->next = sl;
		list->next	= NULL;
		list->prev	= NULL;
		
		if (list == m_dez_op_current)
		{
			m_dez_op_current = sl;
		}
		
		dez_list_add_le(sl, list, lc->level);
		dez_list_add_le(sl, node, level);
	}
	
	return 0;
}

static int dez_list_is_le (DEZ_NODE *node)
{
	DEZ_NODE *last_fetch;
	DEZ_NODE_EXPR *expr;
	
	last_fetch = dez_list_get_last_fetch(node);
	
	if (last_fetch == NULL)
	{
		return -1;
	}
	
	expr = (DEZ_NODE_EXPR *)(last_fetch->content);
	
	if (
		expr != NULL &&
		expr->op1_node == NULL &&
		(last_fetch->zop->op1.op_type == IS_TMP_VAR || last_fetch->zop->op1.op_type == IS_VAR)
	)
	{
		return 0;
	}
	
	return -1;
}

static DEZ_NODE *dez_list_find_dest (DEZ_NODE *le)
{
	DEZ_NODE *p = m_dez_op_current;
	DEZ_NODE *last_fetch = dez_list_get_last_fetch(le);
	
	if (last_fetch == NULL)
	{
		return NULL;
	}
	
	while(p != NULL)
	{
		DEZ_NODE_EXPR *c;
		DEZ_NODE *fetch;
		
		if (p->dez_op != DEZ_OP_ASSIGN)
		{
			p = p->prev;
			continue;
		}

		c = (DEZ_NODE_EXPR *)(p->content);
		
		if (c == NULL)
		{
			p = p->prev;
			continue;
		}
		
		fetch	= c->op2_node;
		
		while (fetch != NULL)
		{
			if (
				fetch->dez_op == DEZ_OP_FETCH_DIM &&
				((DEZ_NODE_EXPR *)(fetch->content))->op1_node != NULL &&
				fetch->zop->op1.op_type == last_fetch->zop->op1.op_type &&
				fetch->zop->op1.u.var == last_fetch->zop->op1.u.var
			)
			{
				return p;
			}
			
			fetch	= ((DEZ_NODE_EXPR *)(fetch->content))->op1_node;
		}

		p = p->prev;
	}

	return NULL;
}

static int dez_list_is_dest (DEZ_NODE *node, znode *zn)
{
	if (node->dez_op == DEZ_OP_LIST)
	{
		DEZ_NODE_LIST *c = (DEZ_NODE_LIST *)(node->content);
		
		if (
			c != NULL										&&
			c->dest_node != NULL							&&
			c->dest_node->zop != NULL						&&
			c->dest_node->zop->op1.op_type == zn->op_type	&&
			c->dest_node->zop->op1.u.var == zn->u.var
		)
		{
			return 0;
		}
	}
	
	return -1;
}

static DEZ_NODE *find_tmp_node (znode *zn)
{
	DEZ_NODE *p = m_dez_op_current;
	
	while(p != NULL)
	{
		if (
			p->zop != NULL							&&
			p->zop->result.op_type == zn->op_type	&&
			p->zop->result.u.var == zn->u.var
		)
		{
			return p;
		}
		
		p = p->prev;
	}
	
	return NULL;
}

static DEZ_NODE *fetch_node (DEZ_NODE *node)
{
	if (node == NULL || node->prev == NULL)
	{
		return NULL;
	}
	
	node->prev->next = node->next;
	if (node->next != NULL) node->next->prev = node->prev;
	
	if (node == m_dez_op_current)
	{
		m_dez_op_current = node->prev;
	}
	
	node->prev = NULL;
	node->next = NULL;
	
	return node;
}

static DEZ_NODE *fetch_current_node (void)
{
	DEZ_NODE *p = m_dez_op_current;
	
	if (p == NULL || p->prev == NULL)
	{
		return NULL;
	}
	
	p->prev->next = NULL;
	m_dez_op_current = p->prev;
	
	p->prev = NULL;
	
	return p;
}

static DEZ_NODE *fetch_tmp_node (znode *zn)
{
	DEZ_NODE *p = m_dez_op_current;
	zend_op *zop = m_zend_op_current-m_opc_num;
	
	if (zn->op_type == IS_TMP_VAR || zn->op_type == IS_VAR)
	{
		while (zop >= m_zend_op_start)
		{
			if (
				zop->result.op_type == zn->op_type	&&
				zop->result.u.var == zn->u.var
			)
			{
				break;
			}
			
			zop--;
		}
		
		if (zop < m_zend_op_start)						/* not found */
		{
			return NULL;
		}
		
		while(p != NULL)
		{
			if (p->zop != NULL)
			{
				if (p->zop < zop)
				{
					break;
				}
				else if (
					p->zop->result.op_type == zn->op_type	&&
					p->zop->result.u.var == zn->u.var
				)
				{
					if (p->prev != NULL) p->prev->next = p->next;
					if (p->next != NULL) p->next->prev = p->prev;
					
					if (p == m_dez_op_current)
					{
						m_dez_op_current = p->prev;
					}
					
					p->prev	= NULL;
					p->next	= NULL;
					
					return p;
				}
			}
			
			p = p->prev;
		}
	}
	
	/*-- fetch list node --*/
	p = m_dez_op_current;
	if(p != NULL)
	{
		if (dez_list_is_dest(p, zn) == 0)
		{
			if (p->prev != NULL) p->prev->next = p->next;
			if (p->next != NULL) p->next->prev = p->prev;
			
			m_dez_op_current = p->prev;
			
			p->prev	= NULL;
			p->next	= NULL;
			
			return p;
		}
	}
	
	return NULL;
}

static DEZ_NODE *fetch_call_ini_node (znode *zn)
{
	DEZ_NODE *p = fetch_tmp_node(zn);
	
	if (p != NULL)
	{
		return p;
	}
	
	if (
		zn->op_type == IS_CONST &&
		zn->u.constant.type == IS_STRING
	)
	{
		p = m_dez_op_current;
		
		while(p != NULL)
		{
			if (
				p->dez_op == DEZ_OP_CALL_INIT			&&
				p->zop != NULL							&&
				p->zop->op2.op_type == IS_CONST			&&
				p->zop->op2.u.constant.type == IS_STRING&&
				strcmp((char *)(p->zop->op2.u.var), (char *)(zn->u.var)) == 0
			)
			{
				return fetch_node(p);
			}
			
			p = p->prev;
		}
	}
	else
	{
		p = m_dez_op_current;
		
		while(p != NULL)
		{
			if (
				p->dez_op == DEZ_OP_CALL_INIT			&&
				p->zop != NULL							&&
				p->zop->op2.op_type == zn->op_type		&&
//				p->zop->op2.u.constant.type == zn->u.constant.type &&
				p->zop->op2.u.var == zn->u.var
			)
			{
				return fetch_node(p);
			}
			
			p = p->prev;
		}
	}
	
	return NULL;
}

static DEZ_NODE *fetch_jmp_src_node (int jmpcode, int dest)
{
	DEZ_NODE *p = m_dez_op_current;
	
	while(p != NULL)
	{
		if (
			p->zop != NULL							&&
			p->zop->opcode == jmpcode				&&
			p->zop->op2.op_type == IS_UNUSED		&&
			p->zop->op2.u.opline_num == dest
		)
		{
			if (p->prev != NULL) p->prev->next = p->next;
			if (p->next != NULL) p->next->prev = p->prev;
			
			if (p == m_dez_op_current)
			{
				m_dez_op_current = p->prev;
			}
			
			p->prev	= NULL;
			p->next	= NULL;
			
			return p;
		}
		
		p = p->prev;
	}
	
	return NULL;
}

static DEZ_NODE *get_jmp_dest_node (int dest)
{
	DEZ_NODE *p = m_dez_op_current;
	
	if (
		p->zop != NULL								&&
		get_zend_linenum(p) < dest
	)
	{
		return NULL;
	}
	
	while(p->prev != NULL)
	{
		if (
			p->prev->zop != NULL					&&
			get_zend_linenum(p->prev) < dest
		)
		{
			break;
		}
		
		p = p->prev;
	}
	
	if (p->prev == NULL)
	{
		p = p->next;
	}
	
	return p;
}

static DEZ_NODE *fetch_jmp_dest_node (int dest)
{
	DEZ_NODE *p = get_jmp_dest_node(dest);
	
	if (p == NULL)
	{
		return NULL;
	}
	
	m_dez_op_current = p->prev;
	m_dez_op_current->next = NULL;
	
	p->prev	= NULL;
	
	return p;
}

static DEZ_NODE *find_last_node (int dez_op)
{
	DEZ_NODE *p = m_dez_op_current;
	
	while(p != NULL)
	{
		if (p->dez_op == dez_op)
		{
			break;
		}
		
		p = p->prev;
	}
	
	return p;
}

static DEZ_NODE *find_last_node_ex (int dez_op, znode *result, znode *op1, znode *op2)
{
	DEZ_NODE *p = m_dez_op_current;
	znode *zn;
	
	while(p != NULL)
	{
		if (p->dez_op == dez_op)
		{
			int found = 1;
			
			if (result != NULL)
			{
				zn = &(p->zop->result);
				
				if (
					zn->op_type != result->op_type		||
					zn->u.var != result->u.var
				)
				{
					found = 0;
				}
			}
			
			if (op1 != NULL)
			{
				zn = &(p->zop->op1);
				
				if (
					zn->op_type != op1->op_type		||
					zn->u.var != op1->u.var
				)
				{
					found = 0;
				}
			}
			
			if (op2 != NULL)
			{
				zn = &(p->zop->op2);
				
				if (
					zn->op_type != op2->op_type		||
					zn->u.var != op2->u.var
				)
				{
					found = 0;
				}
			}
			
			if (found != 0)
			{
				return p;
			}
		}
		
		p = p->prev;
	}
	
	return NULL;
}

static int dez_is_first_node (DEZ_NODE *node)
{
	if (node == NULL)
	{
		return 0;
	}
	
	node = node->prev;
	
	while (node != NULL)
	{
		if (node->dez_op != DEZ_OP_NOP)
		{
			return -1;
		}
		
		node = node->prev;
	}
	
	return 0;
}

static int dez_branch_get_range (DEZ_NODE *parent, int *header, int *tailer)
{
	if (
		parent == NULL			||
		parent->content == NULL	||
		header == NULL			||
		tailer == NULL
	)
	{
		return -1;
	}
	
	if (parent->dez_op == DEZ_OP_FOR)
	{
		DEZ_NODE *before_node = ((DEZ_NODE_FOR *)(parent->content))->before_node;
		
		if (before_node != NULL)
		{
			*header = get_zend_linenum(before_node)+1;
		}
		else
		{
			*header = get_prev_zend_linenum(parent)+1;
		}
	}
	else
	{
		*header = get_prev_zend_linenum(parent)+1;
	}
	
	if (
		parent->dez_op == DEZ_OP_DO	||											/* do{...}while() */
		parent->dez_op == DEZ_OP_WHILE && parent->zop->opcode == ZEND_JMP		/* while(true) */
	)
	{
		*tailer = get_zend_linenum(parent);
	}
	else
	{
		DEZ_NODE *lastnode;
		
		lastnode = parent;
		
		while(1)
		{
			DEZ_NODE *sub;
			
			sub = dez_get_last_sub_node(lastnode);
			
			if (sub == NULL)												/* no sub node */
			{
				break;
			}
			
			lastnode = sub;
			
			if (
				lastnode->dez_op == DEZ_OP_DO	||										/* do{...}while() */
				lastnode->dez_op == DEZ_OP_WHILE && lastnode->zop->opcode == ZEND_JMP	/* while(true) */
			)
			{
				break;
			}
		}
		
		*tailer = get_zend_linenum(lastnode);
	}
	
	return 0;
}

static int dez_enter_branch (void)
{
	DEZ_NODE_EXPR *content;
	
	content = (DEZ_NODE_EXPR *)(m_dez_op_current->content);
	
	if (content->branch_node == NULL)
	{
		content->branch_node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
		if (content->branch_node == NULL)
		{
			return -1;
		}
		
		content->branch_node->dez_op	= DEZ_OP_NOP;
		content->branch_node->zop		= NULL;
		content->branch_node->content	= NULL;
		content->branch_node->prev		= NULL;
		content->branch_node->next		= NULL;
	}
	
	dez_node_push(m_dez_op_current);
	m_dez_op_current = content->branch_node;
		
	return 0;
}

static int dez_enter_branch_ex (DEZ_NODE *node)
{
	DEZ_NODE_EXPR *content;
	
	content = (DEZ_NODE_EXPR *)(node->content);
	content->branch_node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (content->branch_node == NULL)
	{
		return -1;
	}
	
	dez_node_push(node);
	
	content->branch_node->dez_op	= DEZ_OP_NOP;
	content->branch_node->zop		= NULL;
	content->branch_node->content	= NULL;
	content->branch_node->prev		= NULL;
	content->branch_node->next		= node->next;
	if (content->branch_node->next != NULL) content->branch_node->next->prev = content->branch_node;
	
	if (node == m_dez_op_current)
	{
		m_dez_op_current = content->branch_node;
	}
	
	return 0;
}

// enterelse = 0: don't enter else node, 1: enter else node
static int dez_exit_branch (int enterelse)
{
	DEZ_NODE *node, *els, *tmp, *m_dez_op_current2;
	DEZ_NODE_EXPR *content;
	int nextline, dest;
	int remove_node = 0;
	int dup_jmp = 0;
	zend_op *cur_zop;
	
	node = dez_node_pop();
	
	if (node == NULL)
	{
		return -1;
	}
	
	cur_zop = ZEND_GET_ORI(m_zend_op_current) - m_opc_num + m_zend_op_match_n;
	
	content = (DEZ_NODE_EXPR *)(node->content);
	
	m_dez_op_current2 = NULL;
	els = NULL;
	nextline = ZEND_LINENUM(cur_zop) + 1;
	
	if (node->dez_op  == DEZ_OP_IF)							/* if */
	{
		if (
			enterelse == 1	&&								/* need enter else node */
			node->zop->opcode != ZEND_JMP					/* not if (false) */
		)
		{
			int dest;
			
			dest = dez_get_dest(node);
			
			if (dest == nextline)							/* there maybe is else node */
			{
				DEZ_NODE *lastnode = NULL;
				int jmpdest;
				
				tmp = dez_get_last_sub_node(node);
				
				while(tmp != NULL)
				{
					lastnode = tmp;
					tmp = dez_get_last_sub_node(tmp);
				}
				
				jmpdest = dez_get_dest(lastnode);
				
				if (
					lastnode != NULL	&&
					lastnode->dez_op == DEZ_OP_IF	&&			/* if */
					lastnode->zop->opcode == ZEND_JMP &&		/* if (false) */
					(jmpdest > dest || jmpdest <= get_prev_zend_linenum(node)) &&	/* has some zend ops */
//					dez_get_branch_end(lastnode) > dest &&		/* has some zend ops */
					dez_branch_is_null(lastnode) == 0			/* the sub branch is null */
				)
				{
					m_dez_op_current = node;
					
					dez_node_cvt_if(DEZ_OP_ELSE, lastnode->zop);/* add else node */
					dez_enter_branch();							/* enter else node */
					
					return 0;
				}
			}
		}
	}
	else if (
		node->dez_op == DEZ_OP_CASE		||					/* case of switch */
		node->dez_op == DEZ_OP_DEFAULT						/* default of switch */
	)
	{
		m_dez_op_current2 = content->op1_node;				/* return to switch node */
	}
	else if (node->dez_op == DEZ_OP_ELSE)					/* else node */
	{
		if (dez_branch_is_null(node) == 0)					/* the branch is null */
		{
			tmp = node->prev;
			tmp->next = node->next;
			node->prev = NULL;
			
			m_dez_op_current2 = tmp;
			
			remove_node = 1;
		}
	}

	if (m_dez_op_current2 == NULL)
	{
		m_dez_op_current = node;
	}
	else
	{
		m_dez_op_current = m_dez_op_current2;
	}
	
	if (node != NULL)
	{
		DEZ_NODE *lastsubnode = dez_get_last_sub_node(node);
			
		dest = dez_get_dest(node);

#if 0
		if (
			dest >= nextline &&
			node->dez_op == DEZ_OP_IF && node->zop->opcode == ZEND_JMP &&	/* maybe break */
			lastsubnode != NULL	&&
			lastsubnode->dez_op == DEZ_OP_IF && lastsubnode->zop->opcode == ZEND_JMP	/* if (false) */
		)
		{
			DEZ_NODE *pp = dez_node_get();
			
			if (
				pp != NULL	&&
				pp->dez_op == DEZ_OP_IF && pp->zop->opcode != ZEND_JMP
			)
			{
				int ppbegin = get_prev_zend_linenum(pp);
				int ppend = dez_get_branch_end(pp);
				
				if (
					(int)(node->zop->op1.u.opline_num) <= ppbegin &&
					(int)(node->zop->op1.u.opline_num) > ppend &&		/* jmp out of branch of node */
					(int)(lastsubnode->zop->op1.u.opline_num) <= ZEND_LINENUM(pp->zop) &&
					(int)(lastsubnode->zop->op1.u.opline_num) > ppbegin	/* jmp to header of pp */
				)
				{
					dez_node_cvt_jmp(DEZ_OP_JMP, lastsubnode->zop);
					return 0;
				}
			}
		}
#endif
		
		if (dest <= get_zend_linenum(node))								/* jump afterward */
		{
			dup_jmp = 1;
		}
		else if (dest >= nextline)
		{
//			if (cur_zop->opcode == ZEND_JMP)
			if (
				lastsubnode != NULL	&&
				lastsubnode->dez_op == DEZ_OP_IF && lastsubnode->zop->opcode == ZEND_JMP	/* if (false) */
			)
			{
				int dest_is_case_default = 0;
				zend_op *zop_dest = m_zend_op_start + lastsubnode->zop->op1.u.opline_num;
				
				if (
					(zop_dest[-1].opcode == ZEND_JMPZ || zop_dest[-1].opcode == ZEND_JMPZNZ)	&&
					zop_dest[-2].opcode == ZEND_CASE
				)														/* the dest is 'case' */
				{
					dest_is_case_default = 1;
				}
				else if (
					zop_dest[-1].opcode == ZEND_BOOL	&&
					zop_dest[-2].opcode == ZEND_JMP
				)														/* the dest is 'default' */
				{
					dest_is_case_default = 1;
				}
				
				if (
					!(
						node->dez_op == DEZ_OP_ELSE				&&
						dez_in_branch(node, DEZ_OP_CASE) == 0	&&		/* within case branch */
						dest_is_case_default							/* the dest node is case or default node */
					)
				)
				{
					dup_jmp = 1;
				}
			}
		}

		if (dup_jmp != 0)
		{
			zend_op *dupzop;
			
			dupzop = dez_dup_zend_op(cur_zop);
			dupzop->opcode = ZEND_JMP;
			dupzop->op1.op_type = IS_UNUSED;
			dupzop->op1.u.opline_num = dest;
			dupzop->op2.op_type = IS_UNUSED;
			dupzop->op2.u.opline_num = 0;
			dupzop->result.op_type = IS_UNUSED;
			dupzop->result.u.opline_num = 0;
			
			dez_node_cvt_jmp(DEZ_OP_JMP, dupzop);
		}
	}

	if (remove_node != 0)
	{	
		dez_node_specs[node->dez_op].dez_node_free_func(node);	/* remove the else node */
	}
	
	return 0;
}

static int dez_check_exit_branch (void)
{
	DEZ_NODE *node;
	int nextline,dest;
	int i;
	
	nextline = ZEND_LINENUM(m_zend_op_current) - m_opc_num + m_zend_op_match_n + 1;
	
	for (i = 0; i < m_node_num; i++)
	{
		node = m_node_stack[i];
		
		if (
			node->dez_op == DEZ_OP_FUNCTION ||
			node->dez_op == DEZ_OP_CLASS
		)
		{
			continue;
		}
		
		dest = dez_get_branch_end(node);
		
		if (dest <= nextline)
		{
			break;
		}
	}
	
#if 0
	if (i < m_node_num)												/* found */
	{
		int n = m_node_num - 1;
		
		/*-- exit child branch tree --*/
		while (n > i)
		{
			dez_exit_branch(0);
			n--;
		}
		
		dez_exit_branch(1);											/* exit self */
	}
#endif
	
	while (i+1 < m_node_num)
	{
		dez_exit_branch(0);
	}
	
	if (i < m_node_num)
	{
		dez_exit_branch(1);
	}
	
	return 0;
}

static int dez_check_exit_all (void)
{
	while(m_node_num > 0)
	{
		DEZ_NODE *node = dez_node_get();
		
		if (
			node->dez_op == DEZ_OP_FUNCTION	||
			node->dez_op == DEZ_OP_CLASS
		)
		{
			break;
		}
		
		dez_exit_branch(0);
	}
	
	return 0;
}
	
#if 0
static int dez_check_exit_branch (void)
{
	int nextline;
	DEZ_NODE *tmp, *node, *els;
	DEZ_NODE_EXPR *content;
	int i,j;
	
	nextline = ZEND_LINENUM(m_zend_op_current - m_opc_num) + 1;
	
	for (i = 0; i < m_node_num; i++)
	{
		int dest;
		
		node = m_node_stack[i];
		
		if (
			node->dez_op == DEZ_OP_FUNCTION ||
			node->dez_op == DEZ_OP_CLASS
		)
		{
			continue;
		}
		
		content = (DEZ_NODE_EXPR *)(node->content);
		
		dest = dez_get_dest(node);
		
		if (
			dest > get_zend_linenum(node) &&						/* jump forward */
			dest <= nextline
		)
		{
			m_dez_op_current = node;
			
			els = NULL;
			
			if (
				node->dez_op  == DEZ_OP_IF &&						/* if */
				node->zop->opcode != ZEND_JMP						/* not if (false) */
			)
			{
				tmp = dez_node_get();
				
				if (
					node != tmp &&
					tmp != NULL	&&
					tmp->dez_op == DEZ_OP_IF	&&				/* if */
					tmp->zop->opcode == ZEND_JMP &&				/* if (false) */
					dez_get_dest(tmp) > nextline &&				/* has some zend ops */
					dez_branch_is_null(tmp) == 0				/* the sub branch is null */
				)
				{
					els = dez_node_pop();
					els->dez_op = DEZ_OP_ELSE;
					els = fetch_node(els);
				}
			}
			else if (
				node->dez_op == DEZ_OP_CASE		||				/* case of switch */
				node->dez_op == DEZ_OP_DEFAULT					/* default of switch */
			)
			{
				m_dez_op_current = content->op1_node;			/* return to switch node */
			}

			/*-- exit all child branchs --*/
			while (m_node_num > i)
			{
				node = m_node_stack[m_node_num-1];
				
				if (node->dez_op == DEZ_OP_ELSE)			/* else node */
				{
					if (dez_branch_is_null(node) == 0)		/* the branch is null */
					{
						tmp = node->prev;
						
						if (m_dez_op_current == node)
						{
							m_dez_op_current = tmp;
						}
						
						tmp->next = node->next;
						node->prev = NULL;
						
						dez_node_specs[node->dez_op].dez_node_free_func(node);	/* remove the else node */
						node = tmp;
					}
				}
				else if (node->dez_op == DEZ_OP_IF && node->zop->opcode == ZEND_JMP)	/* if (false) */
				{
					DEZ_NODE_IF *ifc = (DEZ_NODE_IF *)(node->content);
#if 0					
					node->next = ifc->branch_node->next;		/* moveup all sub node */
					
					ifc->branch_node->next = NULL;
					dez_node_specs[ifc->branch_node->dez_op].dez_node_free_func(ifc->branch_node);
					ifc->branch_node = NULL;
#endif					
					node->dez_op = DEZ_OP_JMP;					/* change this node into JMP (maybe break) */
				}
				
				m_node_num--;
			}
					
			if (els != NULL)
			{
				DEZ_ADD_NODE(els);
				
				dez_enter_branch();								/* enter else branch */
			}
			
			break;
		}
	}
	
	return 0;
}
#endif

/*-- convertor for DEZ_NODE_NOP --*/
static int dez_node_cvt_nop (unsigned char dez_op, zend_op *pzop)
{
	return 0;
}

/*-- convertor for expr --*/
static int dez_node_cvt_expr (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *parent, *node;
	DEZ_NODE_EXPR *content, *c;
	
	parent = dez_node_get();
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->op1_node		= fetch_tmp_node(&(pzop->op1));
	content->op2_node		= fetch_tmp_node(&(pzop->op2));
	
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;
	node->prev		= NULL;
	node->next		= NULL;

	if (
		dez_op == DEZ_OP_ASSIGN				&&
		parent != NULL						&&
		parent->dez_op == DEZ_OP_FOREACH
	)
	{
		DEZ_NODE_FOREACH *fe = (DEZ_NODE_FOREACH *)(parent->content);
		
		if (
			content->op2_node != NULL &&
			content->op2_node->zop->opcode == ZEND_FETCH_DIM_TMP_VAR &&
			content->op2_node->zop->op1.op_type == ZEND_GET_ORI(parent->zop)[1].result.op_type &&
			content->op2_node->zop->op1.u.var == ZEND_GET_ORI(parent->zop)[1].result.u.var
		)
		{
			if (
				fe->value_node == NULL &&
				content->op2_node->zop->op2.u.var == 0
			)
			{
				node->dez_op = DEZ_OP_AS;
				fe->value_node = node;
				
				return 0;
			}
			else if
			(
				fe->key_node == NULL &&
				content->op2_node->zop->op2.u.var == 1
			)
			{
				node->dez_op = DEZ_OP_AS;
				fe->key_node = node;
				
				return 0;
			}
			
		}
		else if (content->op2_node == NULL)
		{
			if (
				fe->value_node == NULL &&
				pzop->op2.op_type == ZEND_GET_ORI(parent->zop)[1].result.op_type &&
				pzop->op2.u.var == ZEND_GET_ORI(parent->zop)[1].result.u.var
			)
			{
				node->dez_op = DEZ_OP_AS;
				fe->value_node = node;
				
				return 0;
			}
		}
	}
	
	if (
		dez_op == DEZ_OP_ASSIGN				&&
		content->op2_node != NULL			&&
		content->op2_node->dez_op == DEZ_OP_FETCH_DIM
	)
	{
		DEZ_NODE *fetch = dez_list_get_last_fetch(node);
		
		if (fetch != NULL)
		{
			c = (DEZ_NODE_EXPR *)(fetch->content);
			
			if (
				c->op1_node != NULL &&
				c->op1_node->dez_op == DEZ_OP_LIST				/* list element */
			)
			{
				DEZ_NODE *list = c->op1_node;
				c->op1_node = NULL;
				
				DEZ_ADD_NODE(list);
				
				dez_list_add_le(list, node, -1);				/* add element into list */
				
				return 0;
			}
		}
	}
	
	if (dez_list_is_le(node) == 0)								/* list element */
	{
		int level;
		DEZ_NODE *list, *dest;
		
		dest = dez_list_find_dest(node);
		
		if (dest != NULL)
		{
			fetch_node(dest);
			
			level = dez_list_get_level(NULL, dest);
			list = dez_list_create(level-1);					/* create an empty list */
			dez_list_add_le(list, dest, level);
			
			DEZ_ADD_NODE(list);
		}
		else
		{
			list = find_last_node(DEZ_OP_LIST);
		}
		
		if (list != NULL)
		{
			dez_list_add_le(list, node, -1);
			
			return 0;
		}
	}
	
	DEZ_ADD_NODE(node);

	if (dez_op == DEZ_OP_QM_ASSIGN && (m_opc_num < 2 || ZEND_GET_ORI(pzop)[1].opcode != ZEND_JMP))			/* qm false */
	{
		return 2;					/* exit branch */
	}
	else
	{
		return 0;
	}
}

/*-- convertor for if --*/
static int dez_node_cvt_if (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *parent, *node;
	DEZ_NODE_IF *content;
	
	parent = dez_node_get();
	
	if (dez_op == DEZ_OP_IF && pzop->opcode != ZEND_JMP)
	{
		DEZ_NODE *current_node = m_dez_op_current;
		
		while(current_node != NULL)
		{
			if (
				current_node->dez_op == DEZ_OP_IF &&
				current_node->zop->opcode == ZEND_JMP
			)														/* if (false) */
			{
				current_node = current_node->prev;
				continue;
			}
			else if
			(
				current_node->dez_op == DEZ_OP_FUNCTION ||
				current_node->dez_op == DEZ_OP_CLASS
			)
			{
				current_node = NULL;
			}
			
			break;
		}
		
		node = find_tmp_node(&(pzop->op1));
		
		
		if (
			node != NULL					&&
			node->dez_op == DEZ_OP_SWITCH	&&
			current_node == node			&&
			ZEND_LINENUM(pzop) >= pzop->op2.u.opline_num			/* ZEND_JMPZ: goto afterward */
		)	/* the end of default of switch */
		{
			return 0;
		}
	}

	content = (DEZ_NODE_IF *)malloc(sizeof(DEZ_NODE_IF));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	
	if (pzop->opcode == ZEND_JMP)								/* if (false) or else */
	{
		content->op1_node 		= NULL;
		content->op2_node 		= NULL;
		content->dest			= pzop->op1.u.opline_num;
	}
	else
	{
		content->op1_node 		= fetch_tmp_node(&(pzop->op1));
		content->op2_node 		= fetch_tmp_node(&(pzop->op2));
		content->dest			= pzop->op2.u.opline_num;
	}
	
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;
	node->prev		= NULL;
	node->next		= NULL;

	DEZ_ADD_NODE(node);

	if (dez_op == DEZ_OP_IF)
	{
		return 1;					/* enter branch */
	}
	else
	{
		return 0;
	}
}

/*-- convertor for DEZ_OP_QM_ASSIGN --*/
static int dez_node_cvt_qm_assign (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node;
	DEZ_NODE_EXPR *content;
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->op1_node		= fetch_tmp_node(&(pzop->op1));
	
	if (m_opc_num >= 2 && ZEND_GET_ORI(pzop)[1].opcode == ZEND_JMP)			/* qm true */
	{
		DEZ_NODE *cond;
		
		/*-- fetch qm condition node --*/
//		content->op2_node = fetch_jmp_src_node (ZEND_JMPZ, (ZEND_LINENUM(pzop)+2);
		cond = dez_node_get();
		if (
			cond != NULL &&
			cond->dez_op == DEZ_OP_IF &&
			((DEZ_NODE_IF *)(cond->content))->dest == ZEND_LINENUM(pzop)+2
		)
		{
			content->op2_node = dez_node_pop();					/* fetch the condition node */
		
			m_dez_op_current = content->op2_node->prev;
			content->op2_node->prev = NULL;
		}
		else
		{
			content->op2_node = NULL;
		}
	}
	else														/* qm false */
	{
		/*-- fetch qm true node --*/
		content->op2_node = fetch_tmp_node (&(pzop->result));
	}
		
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;

	DEZ_ADD_NODE(node);

	return 0;
}

/*-- convertor for DEZ_OP_DO --*/
static int dez_node_cvt_do (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node;
	DEZ_NODE_EXPR *content;
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->op1_node = fetch_tmp_node(&(pzop->op1));
	content->op2_node = NULL;
	content->branch_node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	
	if (content->branch_node == NULL)
	{
		return -1;
	}
	
	content->branch_node->dez_op	= DEZ_OP_NOP;
	content->branch_node->zop		= NULL;
	content->branch_node->content	= NULL;
	content->branch_node->prev		= NULL;
	content->branch_node->next		= fetch_jmp_dest_node(pzop->op2.u.opline_num);
	if (content->branch_node->next != NULL) content->branch_node->next->prev = content->branch_node;
	
	DEZ_ADD_NODE(node);

	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;

	return 0;
}

/*-- convertor for DEZ_OP_FOR --*/
static int dez_node_cvt_for (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node;
	DEZ_NODE_FOR *content;
	
	content = (DEZ_NODE_FOR *)malloc(sizeof(DEZ_NODE_FOR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->cond_node		= fetch_tmp_node(&(pzop->op1));
	
	if (m_dez_op_current->dez_op == DEZ_OP_ASSIGN)
	{
		content->before_node	= fetch_current_node();
	}
	else
	{
		content->before_node	= NULL;
	}
	
	content->after_node		= NULL;
	
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;

	DEZ_ADD_NODE(node);

	return 1;					/* enter branch */
}

/*-- convertor for DEZ_OP_FOREACH --*/
static int dez_node_cvt_foreach (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node;
	DEZ_NODE_FOREACH *content;
	
	content = (DEZ_NODE_FOREACH *)malloc(sizeof(DEZ_NODE_FOREACH));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	
	content->source_node	= fetch_tmp_node(&(pzop->op1));
	content->key_node		= NULL;
	content->value_node		= NULL;
	
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;

	DEZ_ADD_NODE(node);

	return 1;					/* enter branch */
}

/*-- convertor for DEZ_OP_CASE --*/
static int dez_node_cvt_case (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node, *parent, *branch;
	DEZ_NODE_EXPR *content, *swcontent;
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->op1_node		= fetch_tmp_node(&(pzop->op1));
	content->op2_node		= fetch_tmp_node(&(pzop->op2));
	
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;
	node->prev		= NULL;
	node->next		= NULL;

	parent = find_tmp_node(&(pzop->result));
	
	if (parent == NULL)
	{
		return -1;
	}
	
	if (parent->dez_op == DEZ_OP_BOOL)
	{
		if (
			parent->zop->op1.op_type == IS_CONST			&&
			parent->zop->op1.u.constant.type == IS_BOOL		&&
			parent->zop->op1.u.constant.value.lval == 0
		)
		{
			parent->dez_op	= DEZ_OP_SWITCH;
	
			/* set the condition of switch */
			swcontent = (DEZ_NODE_EXPR *)(parent->content);
			swcontent->op1_node = content->op1_node;
			parent->zop->op1 = pzop->op1;
			content->op1_node = NULL;
			
			branch = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
			if (branch == NULL)
			{
				return -1;
			}
			
			branch->dez_op		= DEZ_OP_NOP;
			branch->zop			= NULL;
			branch->content		= NULL;
			branch->prev		= NULL;
			branch->next		= NULL;
			
			swcontent->branch_node = branch;
		}
		else
		{
			return -1;
		}
	}
	else if (parent->dez_op == DEZ_OP_SWITCH)
	{
		branch = ((DEZ_NODE_EXPR *)(parent->content))->branch_node;
		
		while(branch->next != NULL) branch = branch->next;
	}
	else
	{
		return -1;
	}
	
	content->op1_node	= parent;							/* pointer to switch node */
	
	branch->next	= node;
	node->prev		= branch;
	
	m_dez_op_current= node;
	
	return 1;										/* enter case branch */
}

/*-- convertor for DEZ_OP_DEFAULT --*/
static int dez_node_cvt_default (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node, *parent, *branch;
	DEZ_NODE_EXPR *content, *swcontent;
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->op1_node		= NULL;
	content->op2_node		= NULL;
	
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;
	node->prev		= NULL;
	node->next		= NULL;

	while (1)
	{
		DEZ_NODE *tmp;
		
		parent = find_tmp_node(&(ZEND_GET_ORI(pzop)[1].result));
		
		if (parent != NULL)
		{
			break;
		}
		
		tmp = dez_node_get();
		
		if (tmp == NULL)
		{
			free(content);
			free(node);
			
			return 0;
		}
		
		if (
			(tmp->dez_op == DEZ_OP_IF && tmp->zop->opcode == ZEND_JMP)	||		/* if(false) */
			tmp->dez_op == DEZ_OP_CASE									||		/* case */
			dez_get_dest(tmp) >= ZEND_LINENUM(pzop)+2							/* the dest of parent is next node */
		)
		{
			if (ZEND_GET_ORI(pzop) == ZEND_GET_ORI(tmp->zop))					/* is ZEND_JMP of default */
			{
				m_dez_op_current = dez_node_pop();
			}
			else
			{
				dez_exit_branch(0);			//m_dez_op_current = dez_node_pop();
			}
		}
		else
		{
			free(content);
			free(node);
			
			return 0;
		}
	}
	
	if (parent->dez_op == DEZ_OP_BOOL)
	{
		if (
			parent->zop->op1.op_type == IS_CONST			&&
			parent->zop->op1.u.constant.type == IS_BOOL		&&
			parent->zop->op1.u.constant.value.lval == 0
		)
		{
			parent->dez_op	= DEZ_OP_SWITCH;
			
			swcontent = (DEZ_NODE_EXPR *)(parent->content);
			
			branch = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
			if (branch == NULL)
			{
				return -1;
			}
			
			branch->dez_op		= DEZ_OP_NOP;
			branch->zop			= NULL;
			branch->content		= NULL;
			branch->prev		= NULL;
			branch->next		= NULL;
			
			swcontent->branch_node = branch;
		}
		else
		{
			return -1;
		}
	}
	else if (parent->dez_op == DEZ_OP_SWITCH)
	{
		branch = ((DEZ_NODE_EXPR *)(parent->content))->branch_node;
		
		while(branch->next != NULL) branch = branch->next;
	}
	else
	{
		return -1;
	}
	
	content->op1_node	= parent;							/* pointer to switch node */
	
	branch->next	= node;
	node->prev		= branch;
	
	m_dez_op_current= node;
	
	return 1;												/* enter default branch */
}

/*-- convertor for DEZ_OP_FUNCTION or DEZ_OP_CLASS --*/
static int dez_node_cvt_function_or_class (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node;
	
	node = m_dez_op_root;
	
	while(node != NULL)
	{
		if (pzop->extended_value == ZEND_DECLARE_FUNCTION)
		{
			if (node->dez_op == DEZ_OP_FUNCTION)
			{
				DEZ_NODE_FUNCTION *content;
				
				content = (DEZ_NODE_FUNCTION *)(node->content);
				
				if (0 == strcmp(content->name, pzop->op2.u.constant.value.str.val))
				{
					fetch_node(node);
					
					DEZ_ADD_NODE(node);
					
					return 0;
				}
			}
		}
		else if
		(
			pzop->extended_value == ZEND_DECLARE_CLASS	||
			pzop->extended_value == ZEND_DECLARE_INHERITED_CLASS
		)		/* declare class */
		{
			if (node->dez_op == DEZ_OP_CLASS)
			{
				DEZ_NODE_CLASS *content;
				
				content = (DEZ_NODE_CLASS *)(node->content);
				
				if (0 == strcmp(content->name, pzop->op2.u.constant.value.str.val))
				{
					fetch_node(node);
					
					DEZ_ADD_NODE(node);
					
					return 0;
				}
			}
		}
		
		node = node->next;
	}
	
	return 0;
}

/*-- convertor for DEZ_OP_DOUBLE_ARROW --*/
static int dez_node_cvt_double_arrow (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node, *parent;
	DEZ_NODE_DA *content;
	
	content = (DEZ_NODE_DA *)malloc(sizeof(DEZ_NODE_DA));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	parent = fetch_tmp_node(&(pzop->result));
	
	content->branch_node	= NULL;
	content->key_node		= fetch_tmp_node(&(pzop->op2));
	content->value_node		= fetch_tmp_node(&(pzop->op1));
	content->next_node		= parent;
	if (parent != NULL) parent->prev = node;
	
	node->dez_op	= DEZ_OP_ARRAY;
	node->zop		= pzop;
	node->content	= content;
	node->prev		= NULL;
	node->next		= NULL;

	DEZ_ADD_NODE(node);

	return 0;
}

/*-- convertor for DEZ_OP_ARRAY --*/
static int dez_node_cvt_array (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node;
	DEZ_NODE_DA *content;
	
	content = (DEZ_NODE_DA *)malloc(sizeof(DEZ_NODE_DA));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->key_node		= fetch_tmp_node(&(pzop->op2));
	content->value_node		= fetch_tmp_node(&(pzop->op1));
	content->next_node		= NULL;
	
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;

	DEZ_ADD_NODE(node);

	return 0;
}

/*-- convertor for DEZ_OP_HEREDOC --*/
static int dez_node_cvt_heredoc (unsigned char dez_op, zend_op *pzop)
{
	/**********/
	return 0;
}

/*-- convertor for DEZ_OP_DOLLAR_OPEN_CURLY_BRACES --*/
static int dez_node_cvt_dollar_open_curly_braces (unsigned char dez_op, zend_op *pzop)
{
	/**********/
	return 0;
}

/*-- convertor for DEZ_OP_CALL --*/
static int dez_node_cvt_call (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node, *param, *tmp;
	DEZ_NODE_EXPR *content;
	int param_num;
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->op1_node		= fetch_call_ini_node(&(pzop->op1));
	
	param = NULL;
	tmp = m_dez_op_current;
	param_num = pzop->extended_value;
	
	while (tmp != NULL && param_num > 0)
	{
		DEZ_NODE *prev = tmp->prev;
		
		if (tmp->dez_op == DEZ_OP_CALL_PARAM)
		{
			if (tmp == m_dez_op_current)
			{
				m_dez_op_current = prev;
			}
			
			if (tmp->prev != NULL)
			{
				tmp->prev->next = tmp->next;
				tmp->prev = NULL;
			}
			
			if (tmp->next != NULL)
			{
				tmp->next->prev = prev;
				tmp->next = NULL;
			}
			
			tmp->next = param;
			param = tmp;

			param_num--;
		}
		
		tmp = prev;
	}
	
	content->op2_node = param;
	
	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;
	node->next		= NULL;

	if (pzop->opcode == ZEND_DO_FCALL_BY_NAME)
	{
		if (m_dez_op_current->dez_op == DEZ_OP_NEW)
		{
			content = (DEZ_NODE_EXPR *)(m_dez_op_current->content);
			
			if (content->op1_node != NULL)
			{
				((DEZ_NODE_EXPR *)(node->content))->op1_node = content->op1_node;
			}
			
			content->op1_node = node;
			
			return 0;
		}
	}
	
	DEZ_ADD_NODE(node);

	return 0;
}

/*-- convertor for DEZ_OP_BOOL --*/
static int dez_node_cvt_bool (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *node, *tmp;
	DEZ_NODE_EXPR *content;
	
	if (
		pzop->op1.op_type == IS_CONST &&
		pzop->op1.u.constant.type == IS_BOOL &&
		pzop->op1.u.constant.value.lval == 1 &&
		ZEND_GET_ORI(pzop)[-1].opcode == ZEND_JMP
	)								/* default of switch */
	{
		return dez_node_cvt_default(DEZ_OP_DEFAULT, ZEND_GET_ORI(pzop)-1);
	}		
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->op1_node		= NULL;
	content->op2_node		= NULL;

	node->dez_op			= dez_op;
	node->zop				= pzop;
	node->content			= content;
	node->prev				= NULL;
	node->next				= NULL;
	
	tmp = fetch_tmp_node(&(pzop->result));
	
	if (tmp == NULL)
	{
		DEZ_ADD_NODE(node);

		return 0;
	}
	
	if (tmp->dez_op == DEZ_OP_LOGICAL_OR || tmp->dez_op == DEZ_OP_LOGICAL_AND)
	{
		content->op1_node	= fetch_tmp_node(&(pzop->op1));	/* 2nd condition */
		
		content->op2_node	= tmp;							/* 1st condition */
		
		node->dez_op		= tmp->dez_op;
		
		DEZ_ADD_NODE(node);

		return 0;
	}
	else
	{
		return -1;
	}
}


static int dez_add_jmp_node(zend_op *pzop)
{
	DEZ_NODE *node;
	DEZ_NODE_EXPR *content;
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->op1_node		= NULL;
	content->op2_node		= NULL;
	
	node->dez_op	= DEZ_OP_JMP;
	node->zop		= pzop;
	node->content	= content;
	node->prev		= NULL;
	node->next		= NULL;
	
	DEZ_ADD_NODE(node);
	
	return 0;
}	

/*-- convertor for DEZ_OP_JMP --*/
static int dez_node_cvt_jmp (unsigned char dez_op, zend_op *pzop)
{
	DEZ_NODE *parent;
	int p_linenum;
	
	parent	= dez_node_get();
	if (parent == NULL)
	{
		p_linenum = -1;
	}
	else
	{
		p_linenum = get_zend_linenum(parent);
	}
	
	if (ZEND_LINENUM(pzop) < (int)(pzop->op1.u.opline_num))			/* goto forward */
	{
		if (m_max_jmp_dest < pzop->op1.u.opline_num)
		{
			m_max_jmp_dest = pzop->op1.u.opline_num;
		}
		
		if (
			parent != NULL						&&
			parent->dez_op == DEZ_OP_CASE
		)
		{
			zend_op *dest;
			
			dest = m_zend_op_start + pzop->op1.u.opline_num;
			
			if (
				(dest[-1].opcode == ZEND_JMPZ || dest[-1].opcode == ZEND_JMPZNZ)	&&
				dest[-2].opcode == ZEND_CASE
			)														/* the dest is 'case' */
			{
				dez_exit_branch(0);									/* exit the case branch */
				return 0;
			}
			else if (
				dest[-1].opcode == ZEND_BOOL	&&
				dest[-2].opcode == ZEND_JMP
			)														/* the dest is 'default' */
			{
				dez_exit_branch(0);									/* exit the case branch */
				return 0;
			}
		}
		
		return dez_node_cvt_if(DEZ_OP_IF, pzop);					/* add if (false) node */
	}
	else															/* goto afterware */
	{
		int header_linenum;
		if (
			parent != NULL && parent->dez_op == DEZ_OP_FOR &&
			((DEZ_NODE_FOR *)(parent->content))->before_node != NULL
		)
		{
			header_linenum = get_zend_linenum(((DEZ_NODE_FOR *)(parent->content))->before_node);
		}
		else
		{
			header_linenum = get_prev_zend_linenum(parent);
		}
		
		if ((int)(pzop->op1.u.opline_num) > p_linenum)				/* within this branch */
		{
			DEZ_NODE *node, *branch;
			DEZ_NODE_IF *content;
			int dest;
			
			if (
				parent != NULL						&&
				parent->dez_op == DEZ_OP_FOR
			)
			{
				DEZ_NODE_FOR *content;
				
				content = (DEZ_NODE_FOR *)(parent->content);
				if (content == NULL)
				{
					return -1;
				}
				
				if (
					content->after_node != NULL &&
					pzop->op1.u.opline_num <= get_zend_linenum(content->after_node)
				)
				{
					return 0;
				}
			}
#if 0
			else if (
				parent != NULL						&&
				parent->dez_op == DEZ_OP_FOREACH
			)
			{
				DEZ_NODE *dest;
				
				if (pzop->op1.u.opline_num == p_linenum+1)
				{
					return 2;										/* exit foreach branch */
				}
			}
#endif
			
			content = (DEZ_NODE_IF *)malloc(sizeof(DEZ_NODE_IF));
			if (content == NULL)
			{
				return -1;
			}
			
			node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
			if (node == NULL)
			{
				free(content);
				return -1;
			}
			
			branch = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
			if (branch == NULL)
			{
				return -1;
			}
			
			branch->dez_op	= DEZ_OP_NOP;
			branch->zop		= NULL;
			branch->content	= NULL;
			branch->prev	= NULL;
			branch->next	= fetch_jmp_dest_node(pzop->op1.u.opline_num);
			if (branch->next != NULL) branch->next->prev = branch;
			
			content->branch_node	= branch;
			content->op1_node		= NULL;
			content->op2_node		= NULL;
			content->dest			= ZEND_LINENUM(pzop);
			
			node->dez_op	= DEZ_OP_WHILE;
			node->zop		= pzop;/*branch->next->zop;*/
			node->content	= content;
			node->prev		= NULL;
			node->next		= NULL;
			
			dest = dez_get_branch_end(parent);

//			dez_node_cvt_if(DEZ_OP_IF, pzop);					/* add if (false) */

			clear_or_recover_zend_op(ZEND_GET_ORI(pzop)+1, dest-ZEND_LINENUM(pzop)-1, 1);		/* recover the remainder opcodes in this branch */

			DEZ_ADD_NODE(node);									/* add while (true) */
	
			return 0;
		}
		else if (
			(int)(pzop->op1.u.opline_num) <= p_linenum &&
			(int)(pzop->op1.u.opline_num) > header_linenum
		)														/* the dest is the header of this branch */
		{
			int dest;
			
			if (parent == NULL)
			{
				return 0;
			}
			
			dest = dez_get_branch_end(parent);
			
			if (parent->dez_op == DEZ_OP_IF)
			{
				DEZ_NODE *pp;
				int n = dest-ZEND_LINENUM(pzop)-1;
				
				if (parent->zop->opcode != ZEND_JMP)			/* not if (false) */
				{
					parent->dez_op = DEZ_OP_WHILE;
				}
				
				if (dez_in_branch(parent, DEZ_OP_CASE) == 0)	/* the while() is in case branch */
				{
					int i;
					zend_op *zp = ZEND_GET_ORI(pzop)+1;
					
					i = 0;
					while(i < n)
					{
						if (
							(
								zp[i].opcode == ZEND_JMP	&&
								zp[i+1].opcode == ZEND_BOOL
							)	||								/* default node */
							(
								zp[i].opcode == ZEND_CASE	&&
								(zp[i+1].opcode == ZEND_JMPZ || zp[i+1].opcode == ZEND_JMPZNZ)
							)									/* case node */
						)
						{
							break;
						}
						
						i++;
					}
					
					if (i < n)									/* the case or default node was found */
					{
						zend_op *dupzop;
						
						dupzop = dez_dup_zend_op(pzop);
						dupzop->op1.u.opline_num = dest;
						
//						dez_node_cvt_jmp(DEZ_OP_JMP, dupzop);	/* add if (false) */
						
						n = i;
					}
				}
				
				clear_or_recover_zend_op(ZEND_GET_ORI(pzop)+1, n, 0);	/* clear the remainder opcodes in this branch */
	
				dez_node_cvt_if(DEZ_OP_IF, pzop);				/* add if (false) */

				dez_exit_branch(0);								/* exit the branch */
				
				return 0;
			}
			else if (parent->dez_op == DEZ_OP_FOR)
			{
				DEZ_NODE_FOR *content;
				
				content = (DEZ_NODE_FOR *)(parent->content);
				if (content == NULL)
				{
					return -1;
				}
				
				if (content->after_node == NULL)
				{
					content->after_node = fetch_jmp_dest_node(pzop->op1.u.opline_num);
				}
				else if (pzop->op1.u.opline_num == get_zend_linenum(content->after_node))
				{
					clear_or_recover_zend_op(ZEND_GET_ORI(pzop)+1, dest-ZEND_LINENUM(pzop)-1, 0);		/* clear the remainder opcodes in this branch */
					
					dez_node_cvt_if(DEZ_OP_IF, pzop);			/* add if (false) */

					dez_exit_branch(0);							/* exit the branch */
					
//					return dez_node_specs[DEZ_OP_CONTINUE].dez_node_cvt_func (DEZ_OP_CONTINUE, pzop);	/* add continue node */
				}
				
				return 0;
			}
			else if (parent->dez_op == DEZ_OP_FOREACH)
			{
				clear_or_recover_zend_op(ZEND_GET_ORI(pzop)+1, dest-ZEND_LINENUM(pzop)-1, 0);			/* clear the remainder opcodes in this branch */
				
				dez_node_cvt_if(DEZ_OP_IF, pzop);				/* add if (false) */

//				return dez_node_specs[DEZ_OP_CONTINUE].dez_node_cvt_func (DEZ_OP_CONTINUE, pzop);		/* add continue node */
			}
			
			return 0;
		}
		else													/* the dest is without this branch */
		{
			int dest;
			zend_op *prev_zop;
			
			dest = dez_get_branch_end(parent);
			clear_or_recover_zend_op(ZEND_GET_ORI(pzop)+1, dest-ZEND_LINENUM(pzop)-1, 0);				/* clear the remainder opcodes in this branch */

			dest = dez_get_dest(parent);						// dez_get_branch_end(parent);
			
			if (
				dest > ZEND_LINENUM(pzop) &&					/* jump foreward away */
				parent != NULL	&&
				parent->dez_op == DEZ_OP_ELSE
			)													/* break? */
			{
				DEZ_NODE_EXPR *c;
				
				dez_exit_branch(0);								/* exit this branch */
				
				/*-- fetch the sub branch and add them into m_dez_op_current --*/
				c = (DEZ_NODE_EXPR *)(parent->content);
				if (c != NULL && c->branch_node != NULL)		/* the sub branch is exist */
				{
					m_dez_op_current->next = c->branch_node->next;
					if (c->branch_node->next != NULL) c->branch_node->next->prev = m_dez_op_current;
					
					free(c->branch_node);
					c->branch_node = NULL;
					
					while(m_dez_op_current->next != NULL) m_dez_op_current = m_dez_op_current->next;
				}
				
				DEZ_DEL_NODE(parent);							/* remove the else node */
				
				return dez_node_cvt_jmp(DEZ_OP_JMP, pzop);
			}
			
			prev_zop = ZEND_GET_ORI(pzop)-1;
			if (
				m_dez_op_current->dez_op == DEZ_OP_WHILE && m_dez_op_current->zop->opcode == ZEND_JMP &&	/* the previous node is while(true) */
				prev_zop->opcode == ZEND_JMP					&&
				(int)(prev_zop->op1.u.opline_num) <= p_linenum 	&&			/* jmp to header */
				(int)(prev_zop->op1.u.opline_num) > header_linenum			/* ------------- */
			)
			{
				/* do nothing */
			}
			else
			{	
				dez_node_cvt_if(DEZ_OP_IF, pzop);				/* add if (false) node */
			}

			dez_exit_branch(1);									/* exit this branch */

			return 0;
		}
	}
	
	return dez_node_cvt_expr (dez_op, pzop);					/* add jmp node */
}

/*-- convertor for DEZ_OP_FUNC_PARAM --*/
static int dez_node_cvt_func_param (unsigned char dez_op, zend_op *pzop)
{
	static char paramname[1024];
	
	DEZ_NODE *node, *parent, *param;
	DEZ_NODE_EXPR *content;
	DEZ_NODE_FUNCTION *funcc;
	
	parent = dez_node_get();
	
	if (parent == NULL)
	{
		return -1;
	}
	
	if (parent->dez_op != DEZ_OP_FUNCTION)
	{
		return -1;
	}
	
	funcc = (DEZ_NODE_FUNCTION *)(parent->content);
	
	if (funcc == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)malloc(sizeof(DEZ_NODE_EXPR));
	if (content == NULL)
	{
		return -1;
	}
	
	node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (node == NULL)
	{
		free(content);
		return -1;
	}
	
	content->branch_node	= NULL;
	content->op1_node		= fetch_tmp_node(&(pzop->result));
	
#if 0
	if (content->op1_node == NULL)
	{
		sprintf(paramname, "dez_param_%u", pzop->result.u.var);
		dez_add_var(pzop->result.u.var, paramname, strlen(paramname));
	}
#endif
	
	if (pzop->opcode == ZEND_RECV_INIT)
	{
		content->op2_node = fetch_tmp_node(&(pzop->op2));
	}
	else
	{
		content->op2_node = NULL;
	}

	node->dez_op	= dez_op;
	node->zop		= pzop;
	node->content	= content;
	node->prev		= NULL;
	node->next		= NULL;
	
	param = funcc->param_node;
	
	if (param == NULL)
	{
		funcc->param_node = node;
	}
	else
	{
		while(param->next != NULL)
		{
			param = param->next;
		}
	
		param->next		= node;
		node->prev		= param;
	}
	
	return 0;
}

/*-- convertor for DEZ_OP_UNKNOWN --*/
static int dez_node_cvt_unknown (unsigned char dez_op, zend_op *pzop)
{
	/**********/
	return 0;
}


static int dez_node_output_nop(DEZ_NODE *pdez_node)
{
	/******************/
	return 0;
}

static int dez_node_output_expr(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (
		pdez_node->dez_op == DEZ_OP_BW_NOT			||		/* ~ */
		pdez_node->dez_op == DEZ_OP_BOOL_NOT				/* ! */
	)
	{
		printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
		
		if (content->op1_node != NULL)
		{
			dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
		}
		else
		{
			dez_dump_znode(&(pdez_node->zop->op1), 1);
		}
	}
	else if (
		pdez_node->dez_op == DEZ_OP_CONCAT			&&
		pdez_node->zop->opcode == ZEND_ADD_CHAR
	)
	{
		printf ( "(");
		
		if (content->op1_node != NULL)
		{
			dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
		}
		else
		{
			dez_dump_znode(&(pdez_node->zop->op1), 1);
		}
		
		printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
		
		if (content->op2_node != NULL)
		{
			dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
		}
		else
		{
			printf ( "'%c'", (char)(pdez_node->zop->op2.u.constant.value.lval));
		}

		printf ( ")");
	}
	else
	{	
		if (
			pdez_node->dez_op != DEZ_OP_OBJECT_OPERATOR
		)
		{
			printf ( "(");
		}
		
		if (content->op1_node != NULL)
		{
			dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
		}
		else
		{
			dez_dump_znode(&(pdez_node->zop->op1), 1);
		}
		
		printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
		
		if (content->op2_node != NULL)
		{
			dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
		}
		else
		{
			dez_dump_znode(&(pdez_node->zop->op2), (pdez_node->dez_op == DEZ_OP_OBJECT_OPERATOR ? 0: 1));
		}
		
		if (
			pdez_node->dez_op != DEZ_OP_OBJECT_OPERATOR
		)
		{
			printf ( ")");
		}
	}
	
	return 0;
}

static int dez_node_output_cast(DEZ_NODE *pdez_node)
{
	static char *dez_cast_str[] =
	{
		"(unset)",
		"(int)",
		"(double)",
		"(string)",
		"(array)",
		"(object)",
		"(bool)"
	};
	
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_cast_str[pdez_node->zop->extended_value]);
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	return 0;
}

static int dez_node_output_qm_assign(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;
	DEZ_NODE *qm_true;
	DEZ_NODE_EXPR *content1;
	DEZ_NODE *qm_cond;
	DEZ_NODE_EXPR *content2;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	qm_true = content->op2_node;
	if (qm_true == NULL)
	{
		return -1;
	}
	
	content1 = (DEZ_NODE_EXPR *)(qm_true->content);
	if (content1 == NULL)
	{
		return -1;
	}
	
	printf ( "(");
	
	qm_cond = content1->op2_node;
	if (qm_cond == NULL)
	{
		printf ("true");
	}
	else
	{
		content2 = (DEZ_NODE_EXPR *)(qm_cond->content);
		if (content2 == NULL)
		{
			return -1;
		}
		
		if (qm_cond->zop->opcode == ZEND_JMP)
		{
			printf ("false");
		}
		else if (content2->op1_node != NULL)
		{
			dez_node_specs[content2->op1_node->dez_op].dez_node_output_func (content2->op1_node);
		}
		else
		{
			dez_dump_znode(&(qm_cond->zop->op1), 1);
		}
	}
	
	printf ( " ? ");
	
	if (content1->op1_node != NULL)
	{
		dez_node_specs[content1->op1_node->dez_op].dez_node_output_func (content1->op1_node);
	}
	else
	{
		dez_dump_znode(&(qm_true->zop->op1), 1);
	}
	
	printf ( " : ");
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_pre(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), (pdez_node->dez_op == DEZ_OP_FETCH ? 0 : 1));
	}
	
	return 0;
}

static int dez_node_output_pre2(DEZ_NODE *pdez_node)
{
	DEZ_NODE_IF *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_IF *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (pdez_node->dez_op == DEZ_OP_BREAK)
	{
		if (pdez_node->zop->opcode == ZEND_BRK)
		{
			if (
				pdez_node->zop->op2.op_type == IS_CONST &&
				pdez_node->zop->op2.u.constant.type == IS_LONG &&
				pdez_node->zop->op2.u.constant.value.lval == 1
			)
			{
				/* do nothing */
			}
			else
			{
				printf (" ");
				
				if (content->op2_node != NULL)
				{
					dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
				}
				else
				{
					dez_dump_znode(&(pdez_node->zop->op2), 1);
				}
			}
		}
		else						/* ZEND_JMP */
		{
			if (content->dest > 1)
			{
				printf (" %u", content->dest);
			}
		}
	}
	
	return 0;
}

static int dez_node_output_post(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	return 0;
}

static int dez_node_output_assign(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (content->op2_node != NULL)
	{
		dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op2), 1);
	}
	
	return 0;
}

static int dez_node_output_assign_ref(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;
	zend_op *zop;
	zval **tmp;
	TSRMLS_FETCH(); 
	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (content->op2_node != NULL)
	{
		zop = content->op2_node->zop;
		
		if (zop->opcode == ZEND_FETCH_W && zop->op2.u.fetch_type == ZEND_FETCH_STATIC)			/* static variable */
		{
			zend_op_array *op_array;
			
			printf ( "static ");
			
			if (content->op1_node != NULL)
			{
				dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
			}
			else
			{
				dez_dump_znode(&(pdez_node->zop->op1), 1);
			}
			
/*
			dez_add_var (pdez_node->zop->op1.u.var, zop->op1.u.constant.value.str.val, zop->op1.u.constant.value.str.len);
			
			printf ( "static %s", dez_get_varname(&(pdez_node->zop->op1)));
*/

						
			if (m_current_function == NULL)					/* main branch */
			{
				op_array = EG(active_op_array);
			}
			else
			{
				op_array = ((DEZ_NODE_FUNCTION *)(m_current_function->content))->op_array;
			}
			
			tmp = NULL;
			zend_hash_find(op_array->static_variables, zop->op1.u.constant.value.str.val, zop->op1.u.constant.value.str.len+1, (void **)&tmp);
			if (tmp != NULL)		/* init value assigned */
			{
				printf ( " = ");
				dez_dump_zval(**tmp, 1);
			}
			
			return 0;
		}
		else if (zop->opcode == ZEND_FETCH_W && zop->op2.u.fetch_type == ZEND_FETCH_GLOBAL)		/* global variable */
		{
			printf ( "global ");

			if (content->op1_node != NULL)
			{
				dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
			}
			else
			{
				dez_dump_znode(&(pdez_node->zop->op1), 1);
			}
			
/*
			dez_add_var (pdez_node->zop->op1.u.var, zop->op1.u.constant.value.str.val, zop->op1.u.constant.value.str.len);
			
			printf ( "global %s", dez_get_varname(&(pdez_node->zop->op1)));
*/
			
			return 0;
		}
#if 0
		else if (zop->opcode == ZEND_FETCH_W && zop->op2.u.fetch_type == ZEND_FETCH_LOCAL)		/* local variable */
		{
			dez_add_var (pdez_node->zop->op1.u.var, zop->op1.u.constant.value.str.val, zop->op1.u.constant.value.str.len);
			
			printf ( "%s", dez_get_varname(&(pdez_node->zop->op1)));
			
			return 0;
		}
#endif
	}
	
	/*-- a = &b --*/
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (content->op2_node != NULL)
	{
		dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op2), 1);
	}
	
	return 0;
}

static int dez_node_output_include_or_eval(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;
	char *str;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	switch (pdez_node->zop->op2.u.constant.value.lval)
	{
		case ZEND_EVAL:
			str = "eval (";
			break;
		case ZEND_INCLUDE:
			str = "include ";
			break;
		case ZEND_INCLUDE_ONCE:
			str = "include_once ";
			break;
		case ZEND_REQUIRE:
			str = "require ";
			break;
		case ZEND_REQUIRE_ONCE:
			str = "require_once ";
			break;
	}
	
	printf ( str);
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	if (pdez_node->zop->op2.u.constant.value.lval == ZEND_EVAL)
	{
		printf ( ")");
	}
	
	return 0;
}

static int dez_node_output_or_and(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}

	printf ( "(");
	
	if (content->op2_node != NULL)
	{
		DEZ_NODE_EXPR *cond1 = (DEZ_NODE_EXPR *)(content->op2_node->content);
		
		if (cond1->op1_node != NULL)
		{
			dez_node_specs[cond1->op1_node->dez_op].dez_node_output_func (cond1->op1_node);
		}
		else
		{
			dez_dump_znode(&(content->op2_node->zop->op1), 1);
		}
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_new(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
		
/*
		switch(pdez_node->zop->op1.op_type)
		{
			case IS_CONST:
				printf ("%s", pdez_node->zop->op1.u.constant.value.str.val);
				break;
			case 16:
				printf ("%s", dez_get_varname(&(pdez_node->zop->op1)));
				break;
		}
*/
	}
	
	return 0;
}

static int dez_node_output_exit(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ( "exit (");
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_if(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	printf ( "(");
	
	if (pdez_node->zop->opcode == ZEND_JMP)
	{
		printf ( (pdez_node->dez_op == DEZ_OP_WHILE ? "true" : "false"));
	}
	else
	{
		if (content->op1_node != NULL)
		{
			dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
		}
		else
		{
			dez_dump_znode(&(pdez_node->zop->op1), 1);
		}
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_do(DEZ_NODE *pdez_node)
{
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	return 0;
}

static int dez_node_output_for(DEZ_NODE *pdez_node)
{
	DEZ_NODE *node;
	DEZ_NODE_FOR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_FOR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	printf ( "(");
	
	if (content->before_node != NULL)
	{
		dez_node_specs[content->before_node->dez_op].dez_node_output_func (content->before_node);
	}
	
	printf ( "; ");
	
	if (content->cond_node != NULL)
	{
		dez_node_specs[content->cond_node->dez_op].dez_node_output_func (content->cond_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ( "; ");
	
	node = content->after_node;
	while (node != NULL)
	{
		dez_node_specs[node->dez_op].dez_node_output_func (node);
		
		node = node->next;
		
		if (node != NULL)
		{
			printf ( ", ");
		}
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_foreach(DEZ_NODE *pdez_node)
{
	DEZ_NODE *node;
	DEZ_NODE_FOREACH *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_FOREACH *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	printf ( "(");
	
	if (content->source_node != NULL)
	{
		dez_node_specs[content->source_node->dez_op].dez_node_output_func (content->source_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ( " as ");
	
	if (content->key_node != NULL)
	{
		dez_node_specs[content->key_node->dez_op].dez_node_output_func (content->key_node);
		printf ("%s", dez_node_specs[DEZ_OP_DOUBLE_ARROW].desc);
	}
	
	if (content->value_node != NULL)
	{
		dez_node_specs[content->value_node->dez_op].dez_node_output_func (content->value_node);
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_declare(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	printf ( "(");
	
	if (pdez_node->zop->opcode == ZEND_TICKS)
	{
		printf ( "ticks = ");
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_case(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (content->op2_node != NULL)
	{
		dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op2), 1);
	}
	
	printf ( ":");
	
	return 0;
}

static int dez_node_output_default(DEZ_NODE *pdez_node)
{
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	return 0;
}

static int dez_node_output_function(DEZ_NODE *pdez_node)
{
	DEZ_NODE *node;
	DEZ_NODE_FUNCTION *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_FUNCTION *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	printf ("%s", content->name);
	
	printf ( " (");
	
	for (node = content->param_node; node != NULL; node = node->next)
	{
		if (
			content->op_array != NULL &&
			content->op_array->arg_types != NULL &&
			content->op_array->arg_types[node->zop->op1.u.constant.value.lval] == BYREF_FORCE
		)
		{
			printf ("&");
		}

		dez_node_specs[node->dez_op].dez_node_output_func (node);
		
		if (node->next != NULL)
		{
			printf ( ", ");
		}
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_var(DEZ_NODE *pdez_node)
{
	DEZ_NODE_VAR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_VAR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (content->property != NULL)
	{
		printf ("$%s", content->property->arKey);
		
		if (content->property->pData != NULL)
		{
			printf ( " = ");
			
			dez_dump_zval(**((zval **)(content->property->pData)), 1);
		}
	}
	
	return 0;
}

static int dez_node_output_unset(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	printf ( "($");
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 0);
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_isset_or_empty(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (pdez_node->zop->op2.u.constant.value.lval == 1)
	{
		printf ("%s", dez_node_specs[DEZ_OP_ISSET].desc);
	}
	else
	{
		printf ("%s", dez_node_specs[DEZ_OP_EMPTY].desc);
	}
	
	printf ( "(");
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_class(DEZ_NODE *pdez_node)
{
	DEZ_NODE *node;
	DEZ_NODE_CLASS *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_CLASS *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	printf ("%s", content->name);
	
	if (content->parent != NULL)
	{
		printf ( " extends %s", content->parent->name);
	}
	
	return 0;
}

static int dez_node_output_double_arrow(DEZ_NODE *pdez_node)
{
	DEZ_NODE *node;
	DEZ_NODE_DA *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_DA *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (content->next_node != NULL)					/* is not the first element */
	{
		dez_node_output_double_arrow(content->next_node);
		printf ( ", ");
	}
	
	if (pdez_node->zop->op2.op_type != IS_UNUSED)
	{
		if (content->key_node != NULL)
		{
			dez_node_specs[content->key_node->dez_op].dez_node_output_func (content->key_node);
		}
		else
		{
			dez_dump_znode(&(pdez_node->zop->op2), 1);
		}
		
		printf ("%s", dez_node_specs[DEZ_OP_DOUBLE_ARROW].desc);
	}
	
	if (content->value_node != NULL)
	{
		if (content->value_node->zop->opcode == ZEND_FETCH_W)			/* refrence variable */
		{
			printf ( "&");
		}
		
		dez_node_specs[content->value_node->dez_op].dez_node_output_func (content->value_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	return 0;
}

static int dez_node_output_list(DEZ_NODE *pdez_node)
{
	DEZ_NODE_LIST *lc;
	DEZ_NODE *le;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	lc = (DEZ_NODE_LIST *)(pdez_node->content);
	if (lc == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	printf ( "(");
	
	le = lc->le_node;
	while (le != NULL)
	{
		dez_node_specs[le->dez_op].dez_node_output_func (le);
		
		le = le->next;
		
		if (le != NULL)
		{
			printf ( ", ");
		}
	}
	
	printf ( ")");
	
	if (lc->dest_node != NULL)
	{
		DEZ_NODE *last_fetch, *next;
		DEZ_NODE_EXPR *dc = (DEZ_NODE_EXPR *)(lc->dest_node->content);
		
		last_fetch = lc->dest_node;
		while (last_fetch != NULL)
		{
			next = ((DEZ_NODE_EXPR *)(last_fetch->content))->op1_node;
			if (
				next == NULL ||
				next->dez_op != DEZ_OP_FETCH_DIM
			)
			{
				break;
			}
			
			last_fetch = next;
		}
		
		if (
			last_fetch != NULL &&
			(
				((DEZ_NODE_EXPR *)(last_fetch->content))->op1_node != NULL ||
				(last_fetch->zop->op1.op_type != IS_TMP_VAR && last_fetch->zop->op1.op_type != IS_VAR)
			)
		)
		{
			printf ("%s", dez_node_specs[DEZ_OP_ASSIGN].desc);
			
			if (dc->op1_node != NULL)
			{
				dez_node_specs[dc->op1_node->dez_op].dez_node_output_func (dc->op1_node);
			}
			else
			{
				dez_dump_znode(&(lc->dest_node->zop->op1), 1);
			}
		}
	}

	return 0;
}

static int dez_node_output_le(DEZ_NODE *pdez_node)
{
	DEZ_NODE_LE *lec;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	lec = (DEZ_NODE_LE *)(pdez_node->content);
	if (lec == NULL)
	{
		return -1;
	}
	
	if (lec->a_node != NULL)
	{
		if (lec->a_node->dez_op == DEZ_OP_LIST)
		{
			dez_node_specs[lec->a_node->dez_op].dez_node_output_func (lec->a_node);
		}
		else if (lec->a_node->dez_op == DEZ_OP_ASSIGN)
		{
			DEZ_NODE_EXPR *ac = (DEZ_NODE_EXPR *)(lec->a_node->content);
			
			if (ac->op1_node != NULL)
			{
				dez_node_specs[ac->op1_node->dez_op].dez_node_output_func (ac->op1_node);
			}
			else
			{
				dez_dump_znode(&(lec->a_node->zop->op1), 1);
			}
		}
	}
	
	return 0;
}

static int dez_node_output_array(DEZ_NODE *pdez_node)
{
	DEZ_NODE_DA *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_DA *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	printf ( "(");
	
	pdez_node->dez_op = DEZ_OP_DOUBLE_ARROW;
	dez_node_output_double_arrow(pdez_node);
	pdez_node->dez_op = DEZ_OP_ARRAY;
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_heredoc(DEZ_NODE *pdez_node)
{
	/******************/
	return 0;
}

static int dez_node_output_dollar_open_curly_braces(DEZ_NODE *pdez_node)
{
	/******************/
	return 0;
}

static int dez_node_output_call_param(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (pdez_node->zop->opcode == ZEND_SEND_REF)
	{
		printf ( "&");
	}
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	return 0;
}

static int dez_node_output_call_init(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (pdez_node->zop->op1.op_type != IS_UNUSED)
	{
		if (content->op1_node != NULL)
		{
			dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
			
			printf ( "->");
		}
		else
		{
			dez_dump_znode(&(pdez_node->zop->op1), 0);
			
			if (
				pdez_node->zop->op1.op_type == IS_CONST		&&
				pdez_node->zop->op1.u.constant.type == IS_STRING
			)									/* class method calling */
			{
				printf ( "::");
			}
			else
			{
				printf ( "->");
			}
		}
		
	}
	
	if (content->op2_node != NULL)
	{
		dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op2), 0);
	}
	
	return 0;
}

static int dez_node_output_call(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;
	DEZ_NODE *param;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 0);
	}
	
	printf ( " (");
	
	for (param = content->op2_node; param != NULL; param = param->next)
	{
		dez_node_specs[param->dez_op].dez_node_output_func (param);
		
		if (param->next != NULL)
		{
			printf ( ", ");
		}
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_call_ex(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;
	DEZ_NODE *param;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_get_funcname(&(pdez_node->zop->op1)));
	
	printf ( " (");
	
	for (param = content->op2_node; param != NULL; param = param->next)
	{
		dez_node_specs[param->dez_op].dez_node_output_func (param);
		
		if (param->next != NULL)
		{
			printf ( ", ");
		}
	}
	
	printf ( ")");
	
	return 0;
}

static int dez_node_output_fetch_dim(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op1), 1);
	}
	
	printf ( "[");
	
	if (content->op2_node != NULL)
	{
		dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->op2), 1);
	}
	
	printf ( "]");
	
	return 0;
}

static int dez_node_output_init_string(DEZ_NODE *pdez_node)
{
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	return 0;
}

static int dez_node_output_fetch_constant(DEZ_NODE *pdez_node)
{
	dez_dump_znode(&(pdez_node->zop->op1), 0);
	
	return 0;
}

static int dez_node_output_func_param(DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return -1;
	}
	
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content == NULL)
	{
		return -1;
	}
	
	printf ("%s", dez_node_specs[pdez_node->dez_op].desc);
	
	if (content->op1_node != NULL)
	{
		dez_node_specs[content->op1_node->dez_op].dez_node_output_func (content->op1_node);
	}
	else
	{
		dez_dump_znode(&(pdez_node->zop->result), 1);
	}
	
	if (pdez_node->zop->opcode == ZEND_RECV_INIT)
	{
		printf ( " = ");
		
		if (content->op2_node != NULL)
		{
			dez_node_specs[content->op2_node->dez_op].dez_node_output_func (content->op2_node);
		}
		else
		{
			dez_dump_znode(&(pdez_node->zop->op2), 1);
		}
	}
		
	return 0;
}


static int dez_node_output_unknown(DEZ_NODE *pdez_node)
{
	/******************/
	return 0;
}


/*-- free all dez nodes --*/
static void dez_node_free (void)
{
	if (m_dez_op_root != NULL)
	{
		dez_node_specs[m_dez_op_root->dez_op].dez_node_free_func(m_dez_op_root);
		
		m_dez_op_root = NULL;
	}
}


/*-- free function for DEZ_NODE_NOP node --*/
static void dez_node_free_nop (DEZ_NODE *pdez_node)
{
	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	if (pdez_node->content != NULL)
	{
		/**********/
		
		free(pdez_node->content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_expr (DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->op1_node) dez_node_specs[content->op1_node->dez_op].dez_node_free_func(content->op1_node);
		if (content->op2_node) dez_node_specs[content->op2_node->dez_op].dez_node_free_func(content->op2_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_if (DEZ_NODE *pdez_node)
{
	DEZ_NODE_IF *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_IF *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->op1_node) dez_node_specs[content->op1_node->dez_op].dez_node_free_func(content->op1_node);
		if (content->op2_node) dez_node_specs[content->op2_node->dez_op].dez_node_free_func(content->op2_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_for (DEZ_NODE *pdez_node)
{
	DEZ_NODE_FOR *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_FOR *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->before_node) dez_node_specs[content->before_node->dez_op].dez_node_free_func(content->before_node);
		if (content->cond_node) dez_node_specs[content->cond_node->dez_op].dez_node_free_func(content->cond_node);
		if (content->after_node) dez_node_specs[content->after_node->dez_op].dez_node_free_func(content->after_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_foreach (DEZ_NODE *pdez_node)
{
	DEZ_NODE_FOREACH *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_FOREACH *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->source_node) dez_node_specs[content->source_node->dez_op].dez_node_free_func(content->source_node);
		if (content->key_node) dez_node_specs[content->key_node->dez_op].dez_node_free_func(content->key_node);
		if (content->value_node) dez_node_specs[content->value_node->dez_op].dez_node_free_func(content->value_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_case (DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->op2_node) dez_node_specs[content->op2_node->dez_op].dez_node_free_func(content->op2_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_default (DEZ_NODE *pdez_node)
{
	DEZ_NODE_EXPR *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_EXPR *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_function (DEZ_NODE *pdez_node)
{
	DEZ_NODE_FUNCTION *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_FUNCTION *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->param_node) dez_node_specs[content->param_node->dez_op].dez_node_free_func(content->param_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_var (DEZ_NODE *pdez_node)
{
	DEZ_NODE_VAR *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_VAR *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_class (DEZ_NODE *pdez_node)
{
	DEZ_NODE_CLASS *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_CLASS *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_da (DEZ_NODE *pdez_node)
{
	DEZ_NODE_DA *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_DA *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->key_node) dez_node_specs[content->key_node->dez_op].dez_node_free_func(content->key_node);
		if (content->value_node) dez_node_specs[content->value_node->dez_op].dez_node_free_func(content->value_node);
		if (content->next_node) dez_node_specs[content->next_node->dez_op].dez_node_free_func(content->next_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_array (DEZ_NODE *pdez_node)
{
	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	if (pdez_node->content != NULL)
	{
		/**********/
		
		free(pdez_node->content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_list (DEZ_NODE *pdez_node)
{
	DEZ_NODE_LIST *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_LIST *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->le_node) dez_node_specs[content->le_node->dez_op].dez_node_free_func(content->le_node);
		if (content->dest_node) dez_node_specs[content->dest_node->dez_op].dez_node_free_func(content->dest_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_le (DEZ_NODE *pdez_node)
{
	DEZ_NODE_LE *content;

	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	content = (DEZ_NODE_LE *)(pdez_node->content);
	if (content != NULL)
	{
		if (content->branch_node) dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);
		if (content->a_node) dez_node_specs[content->a_node->dez_op].dez_node_free_func(content->a_node);
		
		free(content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_heredoc (DEZ_NODE *pdez_node)
{
	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	if (pdez_node->content != NULL)
	{
		/**********/
		
		free(pdez_node->content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_dollar_open_curly_braces (DEZ_NODE *pdez_node)
{
	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	if (pdez_node->content != NULL)
	{
		/**********/
		
		free(pdez_node->content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}

static void dez_node_free_unknown (DEZ_NODE *pdez_node)
{
	if (pdez_node == NULL)
	{
		return;
	}
	
	/*-- free the next node --*/
	if (pdez_node->next != NULL)
	{
		dez_node_specs[pdez_node->next->dez_op].dez_node_free_func(pdez_node->next);
	}
	
	/*-- free the node content --*/
	if (pdez_node->content != NULL)
	{
		/**********/
		
		free(pdez_node->content);
	}
	
	/*-- free the node self */
	free(pdez_node);
}


/**********************************************************
*  dez_dump_op: dump a dez op
*
*  @param dez_op: the dez op code need to be dumped
*  @return 0: normal, 1: enter a branch, 2: exit the branch, 3: need to continue -1: error
**********************************************************/
static int dez_dump_op (unsigned char dez_op)
{
	return dez_node_specs[dez_op].dez_node_cvt_func (dez_op, m_op_buffer[0]);
}


/**********************************************************
*  dez_dump_zend_op: dump a zend op
*
*  @param pzop:	pointer to the zend_op need to be dumped
*  @return 0: normal, 1: enter a branch, 2: exit the branch, -1: error
**********************************************************/
static int dez_dump_zend_op (zend_op *pzop)
{
//printf ( "%u,", pzop->opcode);
//return 0;

	printf ( "    %6u:", ZEND_LINENUM(pzop));
	
	if (pzop->opcode >= sizeof(ZEND_OP_STRING)/sizeof(ZEND_OP_STRING[0]))
	{
		printf ( "<%u>     ", pzop->opcode);
	}
	else
	{
		printf ("%s", ZEND_OP_STRING[pzop->opcode]);
	}

	dez_dump_znode_ex(&(pzop->result), 1);
	printf ( ", ");

	dez_dump_znode_ex(&(pzop->op1), 1);
	printf ( ", ");

	dez_dump_znode_ex(&(pzop->op2), 1);
	printf ( "\r\n");

	return 0;
	
//	return dez_node_specs[DEZ_OP_UNKNOWN].dez_node_cvt_func (DEZ_OP_UNKNOWN, pzop);
}


/**********************************************************
*  dez_deal_op: deal with a zend_op
*
*  @param pzop:	pointer to the zend_op would be dealed with. NULL means uninitialization
*  @param match_n: used to retreive the number of matching zend_op
*  @return 0: success, 1: enter a branch, 2: exit the branch, -1: error
**********************************************************/
static int dez_deal_op (zend_op *pzop, short *match_n)
{
	static unsigned char *op_masks = NULL;					/* each element: 0: need to continue, 1: not matching, 2: matching */
	static int op_num = 0;
	
	register int i;
	int needcontinues;
	short mn;
	int matching_i;
	int r;
	
	*match_n = 0;
	
	if (op_masks == NULL)									/* initialization */
	{
		op_masks = (unsigned char *)malloc(sizeof(dez_op_types)/sizeof(dez_op_types[0]));
		if (op_masks == NULL)								/* fail to alloc memery */
		{
			return -1;
		}
		
		op_num = sizeof(dez_op_types)/sizeof(dez_op_types[0]);
		
		memset (op_masks, 0, op_num);						/* initialize op_masks */
	}
	
	if (pzop != NULL)
	{
		if (dez_opc_push (pzop) != 0)						/* push the zend op into stack */
		{													/* fail */
			return -1;
		}
	}
	
	needcontinues	= 0;
	mn				= 0;
	for (i = 0; i < op_num; i++)
	{
		if (op_masks[i] == 0)								/* need to continue */
		{
			op_masks[i] = dez_opc_compare (dez_op_types[i].opcs, dez_op_types[i].opcs_len);
		}
		
		switch (op_masks[i])
		{
			case 0:											/* need to continue */
				needcontinues++;
				break;
			case 1:											/* not matching */
				break;
			case 2:											/* matching */
				if (mn < dez_op_types[i].opcs_len)
				{
					mn				= dez_op_types[i].opcs_len;
					matching_i		= i;
				}
				break;
		}
	}
	
	if (pzop == NULL)										/* uninitialization */
	{
		if (m_opc_num > 0)									/* the stack is not empty */
		{
			if (mn > 0)										/* any dez op is matching */
			{
				*match_n = mn;
				dez_dump_op (dez_op_types[matching_i].dez_op);	/* dump the matching dez op */
			}
			else											/* all dez ops ara not matching */
			{
				mn = 1;
				*match_n = mn;
				dez_dump_zend_op (m_op_buffer[0]);			/* dump the zend op at the top of stack */
			}
			
			memset (op_masks, 0, op_num);					/* reset op_masks */
			
			dez_opc_pop(mn);
			
			dez_deal_op (NULL, match_n);
		}
		else
		{
			if (op_masks != NULL)
			{
				free (op_masks);
				op_masks = NULL;
			}
		}
	}
	else if (needcontinues == 0)							/* no one dez op need to continue */
	{
		if (mn > 0)											/* any dez op is matching */
		{
			*match_n = mn;
			
			do
			{
				r = dez_dump_op (dez_op_types[matching_i].dez_op);	/* dump the matching dez op */
			} while(r == 3);								/* continue to deal with the zend op */
		}
		else												/* all dez ops ara not matching */
		{
			mn = 1;
			*match_n = mn;
			
			r = dez_dump_zend_op (m_op_buffer[0]);			/* dump the zend op at the top of stack */
		}
		
		memset (op_masks, 0, op_num);						/* reset op_masks */
		
		return r;
	}
	
	return 0;
}


/**********************************************************
*  dez_deal_op_end: end process
*
*  @param header: the header of dez nodes
*  @param perant: the parent node
*  @return 0: success; other: failed
**********************************************************/
static int dez_deal_node_end(DEZ_NODE *header, DEZ_NODE *parent)
{
	DEZ_NODE_EXPR *content;
	DEZ_NODE *p, *next;
	int begin, end, prevcond;
	DEZ_BRK_CNT_NODE *pbcn_header, *pbcn, *pbcn_next;
	
	pbcn_header	= m_dez_brk_cnt_tail;
	
	begin		= 0;
	end			= 100000;
	prevcond	= -1;
	
	dez_branch_get_range(parent, &begin, &end);

	if (parent != NULL && parent->dez_op == DEZ_OP_DO)
	{
		DEZ_NODE *prev, *sub;
		
		prev = dez_get_last_sub_node(parent);
		
		while(prev)
		{
			if (
				prev->dez_op == DEZ_OP_DO	||										/* do{...}while() */
				prev->dez_op == DEZ_OP_WHILE && prev->zop->opcode == ZEND_JMP		/* while(true) */
			)
			{
				break;
			}
			
			sub = dez_get_last_sub_node(prev);
			
			if (sub == NULL)
			{
				break;
			}
			
			prev = sub;
		}
		
		if (prev == NULL)							/* no sub branch */
		{
			prevcond = get_prev_zend_linenum(parent);
		}
		else
		{
			prevcond = get_zend_linenum(prev);
		}
	}
	else if (parent != NULL && parent->dez_op == DEZ_OP_FOR)
	{
		DEZ_NODE *before_node = ((DEZ_NODE_FOR *)(parent->content))->before_node;
		
		if (before_node != NULL)
		{
			prevcond = get_zend_linenum(before_node);
		}
		else
		{
			prevcond = get_prev_zend_linenum(parent);
		}
	}
	else
	{
		prevcond = get_prev_zend_linenum(parent);
	}
	
	p = header;
	
	while(p != NULL)
	{
		content = (DEZ_NODE_EXPR *)(p->content);
		
		if (p->dez_op == DEZ_OP_IF && p->zop->opcode == ZEND_JMP)	/* if (false) node */
		{
			int dest;
			
			if (content != NULL && content->branch_node != NULL)	/* sub branch is exist */
			{
				dez_node_specs[content->branch_node->dez_op].dez_node_free_func(content->branch_node);	/* remove the sub branch */
				content->branch_node = NULL;
			}
			
			dest = p->zop->op1.u.opline_num;
			
			if (dest < begin || dest > end)							/* jmp out of the branch */
			{
				if (p->next != NULL)
				{
					dez_node_specs[p->next->dez_op].dez_node_free_func(p->next);	/* remove remainder nodes in this  branch */
					p->next = NULL;
				}
			}

			((DEZ_NODE_IF *)content)->dest = 0;						/* maybe break */
			dez_brk_cnt_add(p);
		}
		else if (content != NULL && content->branch_node != NULL)	/* sub branch is exist */
		{
			dez_node_push(p);										/* for get_prev_zend_linenum() */
			
			dez_deal_node_end(content->branch_node, p);				/* deal with the sub branch */

			dez_node_pop();											/* for get_prev_zend_linenum() */
		}

		p = p->next;
	}
	
	if (pbcn_header != NULL)
	{
		pbcn = pbcn_header->next;
	}
	else
	{
		pbcn = m_dez_brk_cnt_root;
	}
	
	while(pbcn != NULL)
	{
		DEZ_NODE *n;
		DEZ_NODE_IF *c;
		int dest;
		int checked;
		
		pbcn_next = pbcn->next;
		
		n = (DEZ_NODE*)(pbcn->node);
		c = (DEZ_NODE_IF *)(n->content);
		dest = n->zop->op1.u.opline_num;
		
		checked = 0;
		
		if (
			parent != NULL							&&
			(
				parent->dez_op == DEZ_OP_WHILE		||
				parent->dez_op == DEZ_OP_DO			||
				parent->dez_op == DEZ_OP_FOR		||
				parent->dez_op == DEZ_OP_FOREACH	||
				parent->dez_op == DEZ_OP_SWITCH
			)
		)														/* loop or switch */
		{
			int endcond;
			if (parent->dez_op == DEZ_OP_WHILE && parent->zop->opcode == ZEND_JMP)	/* while(true) */
			{
				endcond = prevcond+1;
			}
			else
			{
				endcond = get_zend_linenum(parent);
			}
			
			if (dest < begin || dest > end)						/* jmp out of the branch */
			{
				n->dez_op = DEZ_OP_BREAK;
				c->dest++;
				
				checked = 1;
			}
			else if (
				c->dest == 0					&&				/* maybe continue */
				dest > prevcond && dest <= endcond				/* jmp to condition */
			)
			{
				n->dez_op = DEZ_OP_CONTINUE;
				
				checked = 1;
			}
		}
		else if (
			parent != NULL						&&
			parent->dez_op == DEZ_OP_IF
		)
		{
			if (
				n->dez_op == DEZ_OP_BREAK		&&
				dest > prevcond					&&				/* jmp to condition */
				dest <= get_zend_linenum(parent)				/*                  */
			)
			{
				parent->dez_op = DEZ_OP_WHILE;					/* IF -> WHILE */
			}
		}
		
		if (checked != 0)										/* break or continue was found */
		{
#if 0
			if (c != NULL && c->branch_node != NULL)			/* sub branch is exist */
			{
				DEZ_NODE *lastsubnode = c->branch_node;
				while(lastsubnode->next != NULL)
				{
					lastsubnode = lastsubnode->next;
				}
				
				lastsubnode->next = n->next;
				if (lastsubnode->next != NULL) lastsubnode->next->prev = lastsubnode;
				
				n->next = c->branch_node->next;
				if (n->next != NULL) n->next->prev = n;
				
				c->branch_node->next = NULL;
				free(c->branch_node);
				c->branch_node = NULL;
			}
#endif
		}
		
		if (dest >= begin && dest <= end)						/* jmp within the branch */
		{
			dez_brk_cnt_del(pbcn);
			
			if (n->dez_op == DEZ_OP_IF)							/* not break/continue */
			{
				DEZ_DEL_NODE(n);
			}
			else if(n->dez_op == DEZ_OP_CONTINUE)				/* the continue node */
			{
				DEZ_NODE *lastsubnode = dez_get_last_sub_node(parent);
				if (lastsubnode == n)							/* the continue node is last node in branch */
				{
					DEZ_DEL_NODE(n);
				}
			}
		}
		
		pbcn = pbcn_next;
	}
	
	return 0;
}

/**********************************************************
*  dez_decompile: decompile some zend ops
*
*  @param ops:	the array of zend_ops would be decompiled
*  @param n:	the number of ops
*  @return 0: success; other: failed
**********************************************************/
static int dez_decompile (zend_op *ops, int n)
{
	int r;
	DEZ_NODE_EXPR *content;
	
static struct _zend_executor_globals *zeg;
	TSRMLS_FETCH(); 
	dez_prep_zend_op(ops, n);						/* pre process the zend op */
		
	m_zend_op_start		= ops;
	m_zend_op_end		= ops+n;
	
	m_zend_op_current	= m_zend_op_start;

	while (m_zend_op_current < m_zend_op_end)
	{
zeg = (struct _zend_executor_globals *)&EG(return_value_ptr_ptr);
//dez_dump_zend_op(m_zend_op_current);	/****** for debug */
//m_zend_op_current++;
//continue;

		r = dez_deal_op (m_zend_op_current, &m_zend_op_match_n);	/* deal with a zend_op */

		if (r == 0)									/* success to deal with the zend_op */
		{
			/* do nothing */
		}
		else if (r == 1)							/* enter a branch */
		{
			dez_enter_branch();
		}
		else if (r == 2)							/* exit the branch */
		{
			dez_exit_branch(1);						/* exit the branch */
		}
		else										/* error */
		{
			return r;
		}
		
		dez_check_exit_branch();
		
		dez_opc_pop (m_zend_op_match_n);			/* pop the matching zend op */

		if (m_opc_num > 0)							/* some zend_ops is in stack */
		{
			dez_opc_refresh();						/* update the opcodes in stack */
		}
		
		m_zend_op_current++;
	}
	
	dez_deal_op(NULL, &m_zend_op_match_n);			/* process the remainder zend op in stack */
	
	dez_check_exit_all();							/* exit all branch */

	dez_deal_node_end(m_dez_op_root, NULL);			/* end process (make BREAK, CONTINUE node) */
	
	dez_brk_cnt_free();								/* free the break/continue list */

	clear_or_recover_zend_op(NULL, 0, 0);			/* clear the opcodes cleared */
	
	return 0;
}


/**********************************************************
*  dez_output: output the zend nodes
*
*  @param header: the header of dez nodes
*  @param perant: the parent node
*  @return 0: success; other: failed
**********************************************************/
static int dez_output (DEZ_NODE *header, DEZ_NODE *parent)
{
	static char m_tab[1024] = {' ',' ','\0'};
	
	static int m_dez_declare = 0;
	static int m_dez_silence = 0;

	DEZ_NODE_EXPR *content;
	DEZ_NODE *p, *next;
	DEZ_NODE *function_node;
	
	if (m_dez_declare > 0)
	{
		m_dez_declare++;
	}
	
	p = header;
	
	while(p != NULL)
	{
		next = p->next;
		 
		if (
			p->dez_op == DEZ_OP_NOP		||
			p->dez_op == DEZ_OP_DECLARE
		)
		{
			p = next;
			continue;
		}
		else if (p->dez_op == DEZ_OP_BEGIN_SILENCE)
		{
			m_dez_silence = 1;
			
			p = next;
			continue;
		}
		else if (p->dez_op == DEZ_OP_END_SILENCE)
		{
			m_dez_silence = 0;
			
			p = next;
			continue;
		}
		
		if (
			next != NULL &&
			next->dez_op == DEZ_OP_DECLARE
		)
		{
			if (m_dez_declare == 0)
			{
				m_dez_declare = 1;									/* enter declare branch */
				printf ("%s", m_tab);
				dez_node_specs[next->dez_op].dez_node_output_func (next);
				printf ("\r\n%s{\r\n", m_tab);
				strcat(m_tab, "  ");
			}
		}
		else
		{
			if (m_dez_declare == 1)
			{
				m_dez_declare = 0;									/* exit declare branch */
				m_tab[strlen(m_tab)-2] = '\0';
				printf ("%s}\r\n\r\n", m_tab);
			}
		}
		
		/*-- remove the last return in function() or main branch --*/
		if (
			next == NULL &&
			(parent == NULL || parent->dez_op == DEZ_OP_FUNCTION) &&
			p->dez_op == DEZ_OP_RETURN
		)															/* the last return */
		{
			break;													/* skip the last return */
		}
		
		if (p->dez_op == DEZ_OP_FUNCTION)
		{
			function_node = m_current_function;						/* save the old function node */
			m_current_function = p;
		}

		printf ("%s", m_tab);
		
		if (m_dez_silence != 0)										/* silence */
		{
			printf ("%s", dez_node_specs[DEZ_OP_BEGIN_SILENCE].desc);
		}
		
		dez_node_specs[p->dez_op].dez_node_output_func (p);
		
		content = (DEZ_NODE_EXPR *)(p->content);
		
		if (content != NULL && content->branch_node != NULL)		/* enter branch */
		{
			printf ("\r\n%s{\r\n", m_tab);
			strcat(m_tab, "  ");
			dez_output (content->branch_node, p);					/* output the branch */
			m_tab[strlen(m_tab)-2] = '\0';
			
			if (p->dez_op == DEZ_OP_DO)
			{
				printf ( "%s}", m_tab);
				p->dez_op = DEZ_OP_WHILE;
				dez_node_output_if(p);								/* output while(...) */
				p->dez_op = DEZ_OP_DO;
				printf ( ";\r\n");
			}
			else
			{
				printf ( "%s}\r\n", m_tab);
			}
			
			if (p->next != NULL && p->next->dez_op != DEZ_OP_ELSE)
			{
				printf ( "\r\n");
			}
		}
		else
		{
			printf ( ";\r\n");
		}

		if (p->dez_op == DEZ_OP_FUNCTION)
		{
			m_current_function = function_node;						/* restore the old function node */
		}
		
		p = next;
	}
	
	if (m_dez_declare > 0)
	{
		m_dez_declare--;

		if (m_dez_declare == 0)										/* exit declare branch */
		{
			m_tab[strlen(m_tab)-2] = '\0';
			printf ( "%s}\r\n\r\n", m_tab);
		}
	}
	
	return 0;
}


/**********************************************************
*  dez_property: decompile properties
*
*  @param ht: properties
*  @return 0: success; other: failed
**********************************************************/
static int dez_property (HashTable *ht)
{
	DEZ_NODE *parent;
	DEZ_NODE_CLASS *ccontent;

	if (ht != NULL)
	{
		Bucket *p = ht->pListHead;
		
		parent = dez_node_get();
		
		/*-- decompile properties --*/
		while(p != NULL)
		{
			DEZ_NODE *node;
			DEZ_NODE_VAR *content;

			if (
				parent != NULL		&&
				parent->dez_op == DEZ_OP_CLASS
			)											/* property declaration */
			{
				ccontent = (DEZ_NODE_CLASS *)(parent->content);
				
				if (ccontent->parent != NULL)			/* extands */
				{
					HashTable *pht = &(ccontent->parent->default_properties);
					
					Bucket *pp = pht->pListHead;
					
					while(pp != NULL)
					{
						if (
							strcmp((char *)(pp->arKey), (char *)(p->arKey)) == 0 &&
							*((zval **)(pp->pData)) == *((zval **)(p->pData))
						)								/* property for parent class */
						{
							break;
						}
						
						pp = pp->pListNext;
					}
					
					if (pp != NULL)						/* the method belongs parent class */
					{
						p = p->pListNext;
						continue;
					}
				}
			}

			content = (DEZ_NODE_VAR *)malloc(sizeof(DEZ_NODE_VAR));
			if (content == NULL)
			{
				return -1;
			}
			
			node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
			if (node == NULL)
			{
				free(content);
				return -1;
			}
			
			content->branch_node	= NULL;
			content->property		= p;
			
			node->dez_op			= DEZ_OP_VAR;
			node->zop				= NULL;
			node->content			= content;
		
			DEZ_ADD_NODE(node);
			
			p = p->pListNext;
		}
	}
	
	return 0;
}


/**********************************************************
*  dez_function: decompile functions
*
*  @param ht: function_table
*  @return 0: success; other: failed
**********************************************************/
static int dez_function (HashTable *ht)
{
	static zend_op_array *op_array;
	DEZ_NODE *parent;
	DEZ_NODE_CLASS *ccontent;

	if (ht != NULL)
	{
		Bucket *p = ht->pListHead;
		
		parent = dez_node_get();
		
		/*-- decompile the user functions --*/
		while(p != NULL)
		{
			op_array = (zend_op_array *)(p->pData);
			
			if (
				op_array != NULL	&&
				op_array->type == 2					/* user function */
			)
			{
				DEZ_NODE *node;
				DEZ_NODE_FUNCTION *content;
				
				if (
					parent != NULL		&&
					parent->dez_op == DEZ_OP_CLASS
				)									/* method declaration */
				{
					ccontent = (DEZ_NODE_CLASS *)(parent->content);
					
					if (ccontent->parent != NULL)	/* extands */
					{
						HashTable *pht = &(ccontent->parent->function_table);
						
						Bucket *pp = pht->pListHead;
						
						while(pp != NULL)
						{
							if (((zend_op_array *)(pp->pData))->opcodes == op_array->opcodes)	/* function for parent class */
							{
								break;
							}
							
							pp = pp->pListNext;
						}
						
						if (pp != NULL)				/* the method belongs parent class */
						{
							p = p->pListNext;
							continue;
						}
					}
				}

				content = (DEZ_NODE_FUNCTION *)malloc(sizeof(DEZ_NODE_FUNCTION));
				if (content == NULL)
				{
					return -1;
				}
				
				node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
				if (node == NULL)
				{
					free(content);
					return -1;
				}
				
				content->branch_node	= NULL;
				content->param_node		= NULL;
				content->name			= op_array->function_name;
				content->m_dez_var_num	= 0;
				content->op_array		= op_array;
				
				node->dez_op			= DEZ_OP_FUNCTION;
				node->zop				= op_array->opcodes;
				node->content			= content;
			
				DEZ_ADD_NODE(node);
				
//printf("*%s:\r\n", op_array->function_name);
				m_current_function = node;
				
				dez_enter_branch();									/* enter function branch */
				
				dez_decompile (op_array->opcodes, op_array->size);	/* zend op -> dez op */
				
				dez_exit_branch(0);									/* exit function branch */
				
				m_current_function = NULL;
			}
			
			p = p->pListNext;
		}
	}
	
	return 0;
}


/**********************************************************
*  dez_class: decompile classes
*
*  @param none
*  @return 0: success; other: failed
**********************************************************/
static int dez_class (void)
{
	static HashTable *ht;
	static zend_class_entry *c_entry;
	static zend_op_array *op_array;
	TSRMLS_FETCH(); 
	ht = (EG(class_table));
	
	if (ht != NULL)
	{
		Bucket *p = ht->pListHead;
		
		/*-- decompile the user functions --*/
		while(p != NULL)
		{
			c_entry = (zend_class_entry *)(p->pData);
			
			if (
				c_entry != NULL	&&
				c_entry->type == ZEND_USER_CLASS				/* user class */
			)
			{
				DEZ_NODE *node;
				DEZ_NODE_CLASS *content;
				
				content = (DEZ_NODE_CLASS *)malloc(sizeof(DEZ_NODE_CLASS));
				if (content == NULL)
				{
					return -1;
				}
				
				node = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
				if (node == NULL)
				{
					free(content);
					return -1;
				}
				
				content->branch_node	= NULL;
				content->name			= c_entry->name;
				content->parent			= c_entry->parent;
				
				node->dez_op			= DEZ_OP_CLASS;

				node->zop				= NULL;
				node->content			= content;
			
				DEZ_ADD_NODE(node);
				
//printf("class %s:\r\n", c_entry->name);
				
				dez_enter_branch();									/* enter class branch */
				
				dez_property (&(c_entry->default_properties));		/* decompile the properties */
				
				dez_function (&(c_entry->function_table));			/* decompile the motheds */
				
				dez_exit_branch(0);									/* exit class branch */
			}
			
			p = p->pListNext;
		}
	}
	
	return 0;
}


/**********************************************************
*  dez_global: decompile global source
*
*  @param none
*  @return 0: success; other: failed
**********************************************************/
static int dez_global (void)
{
	TSRMLS_FETCH(); 
	m_current_function = NULL;
	
	return dez_decompile (EG(active_op_array)->opcodes, EG(active_op_array)->size);	/* zend op -> dez op */
}


/**********************************************************
*  dez_main: decompile the zend op
*
*  @param none
*  @return 0: success; other: failed
**********************************************************/
int dez_main (void)
{
	TSRMLS_FETCH(); 
	static char *m_Header = 
"/***********************************************************************/\r\n"
"/*                                                                     */\r\n"
"/*  This file is created by Dezender                                   */\r\n"
"/*                                                                     */\r\n"
"/*  Dezender (Decoder for Zend Encoder/SafeGuard):                     */\r\n"
"/*    Version:      0.9.0.1                                            */\r\n"
"/*    Author:       qinvent.com                                        */\r\n"
"/*    Release Date: 2005.10.04                                         */\r\n"
"/*                                                                     */\r\n"
"/***********************************************************************/\r\n"
"\r\n\r\n";

	m_dez_op_root = (DEZ_NODE *)malloc(sizeof(DEZ_NODE));
	if (m_dez_op_root == NULL)						/* fail to alloc memory */
	{
		return -1;
	}
	
	m_dez_op_root->dez_op	= DEZ_OP_NOP;
	m_dez_op_root->zop		= NULL;
	m_dez_op_root->content	= NULL;
	m_dez_op_root->prev		= NULL; 
	m_dez_op_root->next		= NULL;
	
	m_dez_op_current		= m_dez_op_root;
	
	dez_class ();									/* decompile classes */
	
	dez_function (EG(function_table));				/* decompile functions */
	
	dez_global ();									/* decompile global source */
	
	m_current_function = NULL;
	
	printf ( "<?php\r\n%s", m_Header);
	
	dez_output(m_dez_op_root, NULL);				/* output the dez nodes */
	
	printf ( "?>\r\n");
	
	dez_node_free();								/* free dez nodes */
	
	return 0;
}


/************************************************
 * @ dezender.c v1.0 log @
 *
 * Revision 1.0.0.0     lkq       2005/08/10
 * create the file
 * 
 ***********************************************/
