<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :Shop.php                                              */
/*  DATE        :2005/07/17                                            */
/*  DESCRIPTION :ʵ���/��/�ŵ�����                                  */
/*  PROJECT     :��������ϵͳ                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/en/BOD')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/en/BOD')-1);
require_once $REALROOTPATH . '/en/en_common.php';
require_once $REALROOTPATH . '/di/DataSource.php';


/**********************************************************
 *  CShop: �ŵ�����
 *  һ���ŵ����ϵ���ϸ����
 **********************************************************/
class CShop
{
	/*-- ������Ϣ --*/            
	var $id;						/* �ŵ���                  */
	var $name;						/* �ŵ�����                  */
	var $country;					/* ����                      */
	var $prov;						/* ʡ��/��                   */
	var $city;						/* ����                      */
	var $addr;						/* ��ַ                      */
	var $zip;						/* �ʱ�                      */
	var $tel;						/* �绰                      */
	var $fax;						/* ����                      */
	var $website;					/* ��ַ                      */
	var $logo;						/* LOGO                      */
	var $bank_account;				/* �����˺�                  */
	var $tax_no;					/* ˰��                      */
	var $credit_no;					/* ���ÿ���                  */
	var $contact;					/* ��ϵ��                    */
	var $mobile;					/* �ֻ�                      */
	var $email;						/* �����ʼ�                  */
	var $userid;					/* ��¼��                    */
	var $passwd;					/* ��¼����                  */
	var $sa_id;						/* �������۴�����            */
	var $status;					/* ״̬0: �1: ����2: ֹͣ */
	var $notes;						/* ��ע                      */
	var $create_date;				/* ��������                  */

	/*-- ������Ϣ --*/
	var $sa_name;					/* �������۴���������        */
}


/**********************************************************
 *  CShopSet: �ŵ����ϼ�����
 *  ʵ�ֶ��ŵ����ϵ����ӡ��޸ġ���ѯ��ɾ���Ȳ���
 **********************************************************/
class CShopSet
{
	/**********************************************************
	*  Add: ���һ���ŵ�����
	*
	*  @param $object: һ���ŵ����ϵ�ʵ��
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Add ($object)
	{
		global $g_DataSource;
		
		if ($object->passwd != NULL)
		{
			$object->passwd = md5($object->passwd);			 /* ���������hash */
		}
		
		if (get_class($object) ==  strtolower("CShop"))    /* �жϴ�������Ƿ����Ҫ�� */
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
			
			if (!$g_DataSource->Add ( shop, $object_array))
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
	*  Del: ɾ��һ���ŵ�����
	*
	*  @param $indexs: ��ɾ�����ŵ����ϱ�ŵ�����
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Del ($indexs)
	{
		global $g_DataSource;
		
		for ($i = 0; $i < count ($indexs); $i++)
		{
			$ids[$i] = array('id' => $indexs[$i]);
		}
		
		if (!$g_DataSource->Del (shop, $ids))
		{
			return FALSE;
		}
		
		return TRUE;
	}
	
	
	/**********************************************************
	*  Search: ����������ָ���������ŵ�����
	*
	*  @param $objects: ������CShopʵ��������
	*  @param $terms:   ������������
	*  @param $orderby: �Լ���������������������
	*  @param $asc: 	TRUE: ����; FALSE: ����
	*  @param $offset:	�����ĵ�1��ʵ����ƫ��
	*  @param $rows:	������ʵ����
	*  @return �����������ŵ�����������-1��ʾʧ��
	**********************************************************/
	function Search (&$objects, $terms, $orderby, $asc = TRUE, $offset = 0, $rows = 20)
	{
		global $g_DataSource;
		
		if ($orderby == '')
		{
			$orderby = 'id';
		}
		
		$n = $g_DataSource->Search (&$result, shop, $terms, $orderby, $asc, $offset, $rows);
		if ($n > 0)				/* �����ɹ� */
		{
			for ($i = 0; $i < count ($result); ++$i)                    /* ����������������ת�Ƶ������������ */
			{
				$objects[$i] = new CShop();
				
				while (list($rslt_key, $rslt_val) = each ($result[$i]))
				{
					$objects[$i]->$rslt_key = $rslt_val;
				}

				/*-- ���������Ϣ: begin --*/
				$t = array();
				$t[0] = array('id', $objects[$i]->sa_id, $objects[$i]->sa_id, 1);
				$m = $g_DataSource->Search (&$sas, 'sale_agent', $t, '', TRUE, 0, '');
				
				if ($m > 0)
				{
					$objects[$i]->sa_name = $sas[0]['name'];
				}
				/*-- ���������Ϣ: end --*/
			}
		}
		
		return $n;
    }


	/**********************************************************
	*  Update: ����һ���ŵ�����
	*
	*  @param $object: �����µ��ŵ����ϣ�CShop��ʵ������������µ�����ΪNULL
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Update ($object)
	{
		global $g_DataSource;
		
        if ($object->passwd != NULL)
        {
        	$object->passwd = md5($object->passwd);			 /* ���������hash */
        }
        
		if (get_class($object) ==  strtolower("CShop"))    /* �жϴ�������Ƿ����Ҫ�� */
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
			if (!$g_DataSource->Update ('shop', $terms, $object_array))
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
 * @ Shop.php v1.0 log @
 *
 * Revision 1.0.0.0     RD051     2005/07/17
 * create file
 * 
 ***********************************************/
?>