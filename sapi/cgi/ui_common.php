<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :ui_common.php                                         */
/*  DATE        :2005/07/14                                            */
/*  DESCRIPTION :用户界面层/公共模块                                   */
/*  PROJECT     :数字租赁系统                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/ui')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/ui')-1);


$g_PageSize			= 20;						/* 列表页面每页显示的数据行数设置 */


/**********************************************************
*  NextMonth: 计算下n个月的时间
*
*  @param $date: 这个月的时间戳
*  @return 下n个月的时间戳
**********************************************************/
function NextMonth($date, $n = 1)
{
	$tt0	= getdate ($date);
	$t1		= strtotime ("+".$n." month", $date);
	$tt1	= getdate ($t1);
	
	if ($tt0['mday'] >= 28 && $tt1['mday'] <= 10)
	{
		$t1 = strtotime ("-".$tt1['mday']." day", $t1);
	}
		
	return $t1;
}


/**********************************************************
*  NextPayDay: 计算下个计算日
*
*  @param $date: 任意月的结算日字符串（如："2005-12-23"）
*  @return 下个计算日的时间戳
**********************************************************/
function NextPayDay($date)
{
	$t0		= strtotime ($date);
	$tt0	= getdate ($t0);
	$tt1	= getdate ();
	
	if ($tt1['mday'] < $tt0['mday'])		/* 本月结算日还未到 */
	{
		$t1	= mktime(0,0,0,$tt1['mon'],$tt0['mday'],$tt1['year']);
	}
	else
	{
		$t1	= mktime(0,0,0,$tt1['mon']+1,$tt0['mday'],$tt1['year']);
	}
	
	$tt1	= getdate ($t1);
	
	if ($tt0['mday'] > 28 && $tt1['mday'] < 10)
	{
		$t1 = strtotime ("-".$tt1['mday']." day", $t1);
	}
		
	return $t1;
}

/**********************************************************
*  ExitError: 显示错误信息
*
*  @param $error: 错误信息
*  @return none
**********************************************************/
function ExitError($error,$is_close=0)
{
	global $ROOTPATH;
	
	echo "<script>location=\"".$ROOTPATH."/ui/common/Error.php?error=".$error."&is_close=".$is_close."\"</script>";
	exit();
}


/************************************************
 * @ ui_common.php v1.0 log @
 *
 * Revision 1.0.0.0     RD010     2005/07/14
 * create file
 * 
 ***********************************************/
?>