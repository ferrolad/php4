<?
  class c1
  {
    var $a;
    var $b;

    function c1($aa, $bb)
    {
      $a = $aa;
      $b = $bb;
    }

    function seta($aa)
    {
      $a = $aa;
      return $a;
    }
  };

  $o1 = new c1(2,3);
  $r = $o1->seta(6);

  echo $r;
?>

