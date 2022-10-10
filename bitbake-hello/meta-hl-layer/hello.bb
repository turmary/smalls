DESCRIPTION = "Prints Hello World"
PN = 'printhello'
PV = '1'

# duplicated
inherit base

python do_build() {
    bb.plain("********************");
    bb.plain("*                  *");
    bb.plain("*  Hello, World!   *");
    bb.plain("*                  *");
    bb.plain("********************");
}
