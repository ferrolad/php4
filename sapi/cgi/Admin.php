<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :Admin.php                                             */
/*  DATE        :2005/07/17                                            */
/*  DESCRIPTION :ʵ���/��/ϵͳ����Ա����                            */
/*  PROJECT     :��������ϵͳ                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/en/BOD')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/en/BOD')-1);
require_once $REALROOTPATH . '/en/en_common.php';
require_once $REALROOTPATH . '/di/DataSource.php';


/**********************************************************
 *  CAdmin: ϵͳ����Ա����
 *  һ��ϵͳ����Ա���ϵ���ϸ����
 **********************************************************/
class CAdmin
{
	/*-- ������Ϣ --*/            
	var $id;							/* ϵͳ����Ա��� */
	var $userid;						/* ��¼��     */
	var $passwd;						/* ��¼����   */
	var $notes;							/* ��ע       */
}


/**********************************************************
 *  CAdminSet: ϵͳ����Ա���ϼ�����
 *  ʵ�ֶ�ϵͳ����Ա���ϵ����ӡ��޸ġ���ѯ��ɾ���Ȳ���
 **********************************************************/
class CAdminSet
{
	/**********************************************************
	*  Add: ���һ��ϵͳ����Ա����
	*
	*  @param $object: һ��ϵͳ����Ա��ʵ��
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Add ($object)
	{
		global $g_DataSource;
		
		if ($object->passwd != NULL)
		{
			$object->passwd = md5($object->passwd);			 /* ���������hash */
		}
		
		if (get_class($object) ==  strtolower("CAdmin"))    /* �жϴ�������Ƿ����Ҫ�� */
		{
			/*-- ����������ת������������: begin --*/
			$obj_vars = get_object_vars ($object);
			while (list($obj_key, $obj_val) = each ($obj_vars))
			{
				if ($obj_val !== null)                       /* ��$obj_val�����ϸ�ȶ� */
				{
					$object_array[$obj_key] = $obj_val;
				}
			}
			/*-- ����������ת������������: end --*/
			
			if (!$g_DataSource->Add (admin, $object_array))
			{  
				return FALSE;
			}
			
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	
	
	/**********************************************************
	*  Del: ɾ��һ��ϵͳ����Ա����
	*
	*  @param $indexs: ��ɾ����ϵͳ����Ա���ϱ�ŵ�����
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Del ($indexs)
	{
		global $g_DataSource;
		
		for ($i = 0; $i < count ($indexs); $i++)
		{
			$ids[$i] = array('id' => $indexs[$i]);
		}
		
		if (!$g_DataSource->Del (admin, $ids))
		{
			return FALSE;
		}
		
		return TRUE;
	}
	
	
	/**********************************************************
	*  Search: ����������ָ��������ϵͳ����Ա����
	*
	*  @param $objects: ������CAdminʵ��������
	*  @param $terms:   ������������
	*  @param $orderby: �Լ���������������������
	*  @param $asc: 	TRUE: ����; FALSE: ����
	*  @param $offset:	�����ĵ�1��ʵ����ƫ��
	*  @param $rows:	������ʵ����
	*  @return ����������ϵͳ����Ա����������-1��ʾʧ��
	**********************************************************/
	function Search (&$objects, $terms, $orderby, $asc = TRUE, $offset = 0, $rows = 20)
	{
		global $g_DataSource;
		
		if ($orderby == '')
		{
			$orderby = 'id';
		}
		
		$n = $g_DataSource->Search (&$result, admin, $terms, $orderby, $asc, $offset, $rows);
		if ($n > 0)				/* �����ɹ� */
		{
			for ($i = 0; $i < count ($result); ++$i)                    /* ����������������ת�Ƶ������������ */
			{
				$objects[$i] = new CAdmin();
				
				while (list($rslt_key, $rslt_val) = each ($result[$i]))
				{
					$objects[$i]->$rslt_key = $rslt_val;
				}
			}
		}
		
		return $n;
    }


	/**********************************************************
	*  Update: ����һ��ϵͳ����Ա����
	*
	*  @param $object: �����µ�ϵͳ����Ա���ϣ�CAdmin��ʵ������������µ�����ΪNULL
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Update ($object)
	{
		global $g_DataSource;
		
        if ($object->passwd != NULL)
        {
        	$object->passwd = md5($object->passwd);			 /* ���������hash */
        }
        
		if (get_class($object) ==  strtolower("CAdmin"))    /* �жϴ�������Ƿ����Ҫ�� */
		{
	
			/*-- ����������ת������������: begin --*/
			$obj_vars = get_object_vars ($object);
			while (list($obj_key, $obj_val) = each ($obj_vars))
			{
				if ($obj_val !== null)                       /* ��$obj_val�����ϸ�ȶ� */
				{
					if ($obj_key != 'id')
					{
						$object_array[$obj_key] = $obj_val;
					}
				}
			}
			/*-- ����������ת������������: end --*/
	
			$terms['id'] = $object->id;
			if (!$g_DataSource->Update (admin, $terms, $object_array))
			{  
			 return FALSE;
			}
			
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
}


/************************************************
 * @ Admin.php v1.0 log @
 *
 * Revision 1.0.0.0     RD051     2005/07/17
 * create file
 * 
 ***********************************************/
?>