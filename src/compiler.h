#define PHP_compiler_EXTNAME "easy_compiler"
#define PHP_compiler_VERSION "0.0.1"
static unsigned char* encrypt_str(unsigned char *raw);
static unsigned char* decrypt_str(unsigned char *raw);
//define hook
static zend_op_array *(*orig_compile_string)(zval *source_string, char *filename TSRMLS_DC);
static zend_op_array *decrypt_compile_string(zval *source_string, char *filename TSRMLS_DC);
static zend_op_array *decrypt_compile_file(zend_file_handle *file_handle, int type);
//modify opcode
static void modify_opcode(zend_op_array* opline);
//declare exception
zend_class_entry *easy_compiler_exception_class_entry_ptr;
zend_class_entry easy_compiler_exception_ce;
static void throw_exception(char *msg);
//define php func
PHP_FUNCTION(easy_compiler_encrypt);
PHP_FUNCTION(easy_compiler_decrypt);
//define model global arg
ZEND_BEGIN_MODULE_GLOBALS(easy_compiler)
bool is_hook_compile_string;
bool is_hook_compile_file;
ZEND_END_MODULE_GLOBALS(easy_compiler)
