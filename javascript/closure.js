///* http://lipeng1667.github.io/2016/12/20/closure-in-js/ */

function Counter(start) {
    var count = start;
    return {
        increment: function() {
            count++;
        },

        get: function() {
            return count;
        }
    }
}

var foo = Counter(4);
foo.increment();
WScript.echo(foo.get()); // 5
WScript.echo();


function buildList(list) {
    var result = [];
    for (var i = 0; i < list.length; i++) {
        var item = 'item' + i;
        result.push(
            function() {
                WScript.echo(item + ' ' + i + ' ' + list[index++]);
                // WScript.echo(item + ' ' + list[i]);
            }
        );
    }
    index = 0;
    return result;
}

function testList() {
    var fnlist = buildList([1,2,3]);
    // Using j only to help prevent confusion -- could use i.
    for (var j = 0; j < fnlist.length; j++) {
        fnlist[j]();
    }
}

testList() //logs "item2 undefined" 3 times

