<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :ui_common.php                                         */
/*  DATE        :2005/07/14                                            */
/*  DESCRIPTION :�û������/����ģ��                                   */
/*  PROJECT     :��������ϵͳ                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/ui')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/ui')-1);


$g_PageSize			= 20;						/* �б�ҳ��ÿҳ��ʾ�������������� */


/**********************************************************
*  NextMonth: ������n���µ�ʱ��
*
*  @param $date: ����µ�ʱ���
*  @return ��n���µ�ʱ���
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
*  NextPayDay: �����¸�������
*
*  @param $date: �����µĽ������ַ������磺"2005-12-23"��
*  @return �¸������յ�ʱ���
**********************************************************/
function NextPayDay($date)
{
	$t0		= strtotime ($date);
	$tt0	= getdate ($t0);
	$tt1	= getdate ();
	
	if ($tt1['mday'] < $tt0['mday'])		/* ���½����ջ�δ�� */
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
*  ExitError: ��ʾ������Ϣ
*
*  @param $error: ������Ϣ
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