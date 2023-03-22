"use strict";

var $$String = require("melange/stdlib_modules/string.js");
var Int64 = require("melange/stdlib_modules/int64.js");
var List = require("melange/stdlib_modules/list.js");

var Caml = require("melange.runtime/caml.js");
var Caml_int64 = require("melange.runtime/caml_int64.js");
var Caml_string = require("melange.runtime/caml_string.js");

function $less$less(a, b) {
  return Caml_int64.of_int32(Caml_int64.to_int32(a) << b);
}

function $star(a, b) {
  return Caml_int64.of_int32(
    Math.imul(Caml_int64.to_int32(a), Caml_int64.to_int32(b))
  );
}

function $great$great$great(a, b) {
  return Caml_int64.of_int32(Caml_int64.to_int32(a) >> b);
}

function $plus$plus(a, b) {
  return Caml_int64.of_int32(
    (Caml_int64.to_int32(a) + Caml_int64.to_int32(b)) | 0
  );
}

function $caret(a, b) {
  return Caml_int64.of_int32(Caml_int64.to_int32(a) ^ Caml_int64.to_int32(b));
}

function to_base36(num) {
  var to_base36$p = function (num) {
    if (Caml.i64_eq(num, Caml_int64.zero)) {
      return /* [] */ 0;
    }
    var quotient = Caml_int64.div(num, [0, 36]);
    var remainder = Caml_int64.mod_(num, [0, 36]);
    return {
      hd: Caml.i64_lt(remainder, [0, 23])
        ? Caml.i64_lt(remainder, [0, 16])
          ? Caml.i64_lt(remainder, [0, 13])
            ? Caml.i64_neq(remainder, [0, 10])
              ? Caml.i64_neq(remainder, [0, 11])
                ? Caml.i64_neq(remainder, [0, 12])
                  ? String(Caml_int64.to_int32(remainder))
                  : "c"
                : "b"
              : "a"
            : Caml.i64_neq(remainder, [0, 13])
            ? Caml.i64_neq(remainder, [0, 14])
              ? Caml.i64_neq(remainder, [0, 15])
                ? String(Caml_int64.to_int32(remainder))
                : "f"
              : "e"
            : "d"
          : Caml.i64_lt(remainder, [0, 19])
          ? Caml.i64_neq(remainder, [0, 16])
            ? Caml.i64_neq(remainder, [0, 17])
              ? Caml.i64_neq(remainder, [0, 18])
                ? String(Caml_int64.to_int32(remainder))
                : "i"
              : "h"
            : "g"
          : Caml.i64_lt(remainder, [0, 21])
          ? Caml.i64_neq(remainder, [0, 19])
            ? Caml.i64_neq(remainder, [0, 20])
              ? String(Caml_int64.to_int32(remainder))
              : "k"
            : "j"
          : Caml.i64_neq(remainder, [0, 21])
          ? Caml.i64_neq(remainder, [0, 22])
            ? String(Caml_int64.to_int32(remainder))
            : "m"
          : "l"
        : Caml.i64_lt(remainder, [0, 29])
        ? Caml.i64_lt(remainder, [0, 26])
          ? Caml.i64_neq(remainder, [0, 23])
            ? Caml.i64_neq(remainder, [0, 24])
              ? Caml.i64_neq(remainder, [0, 25])
                ? String(Caml_int64.to_int32(remainder))
                : "p"
              : "o"
            : "n"
          : Caml.i64_neq(remainder, [0, 26])
          ? Caml.i64_neq(remainder, [0, 27])
            ? Caml.i64_neq(remainder, [0, 28])
              ? String(Caml_int64.to_int32(remainder))
              : "s"
            : "r"
          : "q"
        : Caml.i64_lt(remainder, [0, 32])
        ? Caml.i64_neq(remainder, [0, 29])
          ? Caml.i64_neq(remainder, [0, 30])
            ? Caml.i64_neq(remainder, [0, 31])
              ? String(Caml_int64.to_int32(remainder))
              : "v"
            : "u"
          : "t"
        : Caml.i64_lt(remainder, [0, 34])
        ? Caml.i64_neq(remainder, [0, 32])
          ? Caml.i64_neq(remainder, [0, 33])
            ? String(Caml_int64.to_int32(remainder))
            : "x"
          : "w"
        : Caml.i64_neq(remainder, [0, 34])
        ? Caml.i64_neq(remainder, [0, 35])
          ? String(Caml_int64.to_int32(remainder))
          : "z"
        : "y",
      tl: to_base36$p(quotient),
    };
  };
  return $$String.concat("", List.rev(to_base36$p(num)));
}

function to_css(number) {
  return "css-" + to_base36(number);
}

function murmur2(str) {
  var len = Caml_int64.of_int32(str.length);
  var h = Caml_int64.mul(len, len);
  var k = Int64.zero;
  var i = 0;
  var len$1 = str.length;
  while (len$1 >= 4) {
    k = Caml_int64.of_int32(
      Caml_string.get(str, i) |
        (Caml_string.get(str, (i + 1) | 0) << 8) |
        (Caml_string.get(str, (i + 2) | 0) << 16) |
        (Caml_string.get(str, (i + 3) | 0) << 24)
    );
    var k_one = Caml_int64.and_(k, [0, 65535]);
    var k_pre_16 = $star(Caml_int64.asr_(k, 16), [0, 59797]);
    var k_16 = $less$less(k_pre_16, 16);
    k = Caml_int64.add(Caml_int64.mul(k_one, [0, 1540483477]), k_16);
    k = $caret(k, $great$great$great(k, 24));
    var first_h = Caml_int64.add(
      Caml_int64.mul(Caml_int64.and_(k, [0, 65535]), [0, 1540483477]),
      $less$less(Caml_int64.mul($great$great$great(k, 16), [0, 59797]), 16)
    );
    var second_h = Caml_int64.add(
      Caml_int64.mul(Caml_int64.and_(h, [0, 65535]), [0, 1540483477]),
      $less$less(Caml_int64.mul($great$great$great(h, 16), [0, 59797]), 16)
    );
    h = $caret(first_h, second_h);
    len$1 = (len$1 - 4) | 0;
    i = (i + 1) | 0;
  }
  h = Caml_int64.xor(h, $great$great$great(h, 13));
  h = $plus$plus(
    $star(Caml_int64.and_(h, [0, 65535]), [0, 1540483477]),
    $star(Caml_int64.asr_(h, 16), [0, 3918856192])
  );
  return Caml_int64.xor(h, $great$great$great(h, 15));
}

function make(str) {
  var number = murmur2(str);
  return to_base36(number);
}

export default make;
