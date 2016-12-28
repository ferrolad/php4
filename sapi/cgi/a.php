<?
  class ctest
  {
    var $a;
    var $b;

    function ctest($a1, $b1)
    {
      $this->a = $a1;
      $this->b = $b1;
    }

    function set($a1, $b1)
    {
      $this->a = $a1;
      $this->b = $b1;
      return 1;
    }
  }

  function func1($a, $b)
  {
    return $a+$b;
  }
?>
