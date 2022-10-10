DESCRIPTION = "I am he second recipe"
PR = "r1"

inherit mybuild

def pyfunc(o):
    print(help(o))

python do_mypatch () {
    bb.note ("(second.bb): running mypatch with MYBUILD_VAR1 = {}".format(d.getVar("MYBUILD_VAR1")) )
    pyfunc(d)
}

export MYBUILD_ARG="005 (second.bb)"

addtask mypatch before do_build

