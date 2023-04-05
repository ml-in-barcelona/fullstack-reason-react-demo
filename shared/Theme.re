type align = [ | `start | `center | `end_];

type justify = [ | `around | `between | `evenly | `start | `center | `end_];

let unit = v => v * 4;
let px = v => `px(unit(v));

module Media = {
  let maxWidth400 = "(max-width: 400px)";
  let onMobile = rules => {
    Css.media(maxWidth400, rules);
  };
};

module Color = {
  let white = Css.white;
  let black = Css.black;
  let reason = Css.hex("db4d3f");
  let react = Css.hex("149eca");
  let ahrefs = Css.hex("ff8800");
  let lightGrey = Css.hex("c1c5cd");
  let darkGrey = Css.hex("292a2d");
  let backgroundBox = Css.hex("2e3c56");
  let brokenWhite = Css.hex("eaecee");
  let white01 = Css.rgba(255, 255, 255, `num(0.1));
};
