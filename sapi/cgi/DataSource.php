<?
/***********************************************************************/
/*                                                                     */
/*  FILE        :DataSource.php                                        */
/*  DATE        :2005/07/12                                            */
/*  DESCRIPTION :���ݽӿڲ�/����Դ��SQL-Server��                       */
/*  PROJECT     :��������ϵͳ                                          */
/*                                                                     */
/***********************************************************************/


if (!isset($REALROOTPATH)) $REALROOTPATH = substr(dirname($HTTP_SERVER_VARS['SCRIPT_FILENAME']).'/', 0, -strlen('/di')-1);
if (!isset($ROOTPATH)) $ROOTPATH = substr(dirname($HTTP_SERVER_VARS['PHP_SELF']).'/',0,-strlen('/di')-1);
require_once $REALROOTPATH . '/di/di_common.php';
require_once $REALROOTPATH . '/di/DBConfig.conf';


static $m_DBH		= 0;										/* ���ݿ����� */


/**********************************************************
 *  CDataSource: ����Դ��SQL-Server����
 *  ʵ�ֶ������Դ洢���ݵ����ӡ��޸ġ���ѯ��ɾ���Ȳ���
 **********************************************************/
class CDataSource
{
	/**********************************************************
	*  Init: ��ʼ������Դ
	*
	*  @param none
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Init ()
	{
		global $m_Host, $m_Port, $m_User, $m_Password, $m_DBH, $m_DB_Name;
		
		if ($m_DBH == 0)				/* ��δ��ʼ�� */
		{
			//$m_DBH = mssql_connect ($m_Host . ":" . $m_Port, $m_User, $m_Password);      /* �������ݿ� */
			$m_DBH = mssql_connect ($m_Host, $m_User, $m_Password);		/* �������ݿ� */
		}
		
		if ($m_DBH == 0)				/* ��ʼ��ʧ�� */
		{
			return FALSE;
		}
		else							/* ��ʼ���ɹ� */
		{
		    return mssql_select_db($m_DB_Name); 						/* ѡ�����ݿ� */
		}
		
		return TRUE;
	}
	
	/**********************************************************
	*  Add: �½�һ����¼
	*
	*  @param $recordtype:	��¼������
	*  @param $record:		����ӵļ�¼
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Add ($recordtype, $record)
	{
		$recordtype = 'tb_'.$recordtype;
		
		/*-- �����������ӵļ�¼�ӹ���sql���: begin --*/
		$fields = "";
		$values = "";
		
		while (list ($rcrd, $rcrd_val) = each ($record))
		{
			if($rcrd == 'id')
			{
				continue;
			}
			
		    $fields = $fields . " " . $rcrd . ",";
		    $values = $values . "'" . htmlspecialchars($rcrd_val,ENT_QUOTES) . "',";
		}
		/*-- �����������ӵļ�¼�ӹ���sql���: end --*/
		
		$fields = substr ($fields, 0, -1);
		$values = substr ($values, 0, -1);
		$rslt = mssql_query ("insert into " . $recordtype . " (" . $fields . ") values (" . $values . ")");

/* debug: begin */
//if ($recordtype=='tb_sale_agent') exit( "insert into " . $recordtype . " (" . $fields . ") values (" . $values . ")");
/* debug: end */

		if ($rslt > 0) 									/* ���ݿ��ѯ���������ֵ */
		{
			return TRUE;
		}
		else 											/* ���ݿ��ѯʧ�ܷ���false */
		{
		    return FALSE;
		}
	}
	
	
	/**********************************************************
	*  Del: ɾ��ָ���ļ�¼
	*
	*  @param $recordtype:	��¼������
	*  @param $indexs:		��ɾ����¼������������
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Del ($recordtype, $indexs)
	{
		global $m_DBH;
		
		$recordtype = 'tb_'.$recordtype;
		
        /*-- һ��һ����ɾ������: begin --*/
        for ($i = 0; $i < count ($indexs); $i++)
        {
            /*-- ����������������е�һ���ӹ���sql���: begin --*/
            $ind = "";
            while (list ($index, $index_val) = each ($indexs[$i]))
            {
                $ind = $ind . " " . $index . " = " . $index_val . " and ";
            }
            $ind = substr ($ind, 0, -5);
			/*-- ����������������е�һ���ӹ���sql���: end -*/

/* debug: begin */
//if ($recordtype=='tb_sale_agent') echo "delete from " . $recordtype . " where " . $ind;
/* debug: end */

            if (!mssql_query ("delete from " . $recordtype . " where " . $ind))
            { 
                return FALSE;
            }

        }
		
		/* һ�����ݶ�û��ɾ�� */
		if (mssql_rows_affected($m_DBH) == 0)           
		{
		    return FALSE;
		}
		/*-- һ��һ����ɾ������: end --*/
		
		return TRUE;
	}
	
	
	/**********************************************************
	*  DelByTerms: ɾ�����������ļ�¼
	*
	*  @param $recordtype:	��¼������
	*  @param $terms:		��ɾ����¼����������
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function DelByTerms ($recordtype, $terms)
	{
        /*-- ��һ��һ��������ƴ����: begin --*/
        $trms = "";
		$resultorder = "";
		$n = 0;
		
		$recordtype = 'tb_'.$recordtype;
		
        for ($i = 0; $i < count ($terms); ++$i)
        {

            if ($terms[$i][3] == 0)     /* һ�������ĵ�4��Ԫ��Ϊ0ʱ,�������ĺ���Ϊ���ڵڶ���Ԫ����С�ڵ�����Ԫ�� */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">'" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<'" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 1)/* һ�������ĵ�4��Ԫ��Ϊ1ʱ,�������ĺ���Ϊ����ڵڶ���Ԫ����С���ڵ�����Ԫ�� */
            {

                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">='" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<='" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 2)/* һ�������ĵ�4��Ԫ��Ϊ2ʱ,�������ĺ���Ϊ���ڵڶ���Ԫ����С���ڵ�����Ԫ�� */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">'" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<='" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 3)/* һ�������ĵ�4��Ԫ��Ϊ3ʱ,�������ĺ���Ϊ����ڵڶ���Ԫ����С�ڵ�����Ԫ�� */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">='" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<'" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 4)/* һ�������ĵ�4��Ԫ��Ϊ4ʱ,�������ĺ���Ϊ���еڶ���Ԫ�� */
            {
                $trm1 = $terms[$i][0] . " LIKE '%" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "%' and ";
                $trm2 = "";
            }

            $trms = $trms . $trm1 . $trm2;
        }
        
		$where = '';
		if ($trms != "")
		{
			$where = " where " . substr($trms, 0, -5);
		}

		$rslt = mssql_query ("delete " . $recordtype . $where);

        if ($rslt > 0)                             /* ���ݿ��ѯ���������ֵ */
        {
            return TRUE;
        }
        else                                       /* ���ݿ��ѯʧ�� */
        {
            return FALSE;
        }
    }
    
		
	/**********************************************************
	*  Search: ����������ָ�������ļ�¼
	*
	*  @param $result:		�������
	*  @param $recordtype:	��¼������
	*  @param $terms:		������������
	*  @param $orderby:		�Լ���������������������
	*  @param $asc: 		TRUE: ����; FALSE: ����
	*  @param $offset:		�����ĵ�1����¼��ƫ��
	*  @param $rows:		�����ļ�¼��
	*  @return ���������ļ�¼������-1��ʾʧ��
	**********************************************************/
	function Search (&$result, $recordtype, $terms, $orderby, $asc, $offset, $rows)
	{
        /*-- ��һ��һ��������ƴ����: begin --*/
        $trms = "";
		$resultorder = "";
		$n = 0;
		
		$recordtype = 'tb_'.$recordtype;
		
        for ($i = 0; $i < count ($terms); ++$i)
        {

            if ($terms[$i][3] == 0)     /* һ�������ĵ�4��Ԫ��Ϊ0ʱ,�������ĺ���Ϊ���ڵڶ���Ԫ����С�ڵ�����Ԫ�� */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">'" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<'" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 1)/* һ�������ĵ�4��Ԫ��Ϊ1ʱ,�������ĺ���Ϊ����ڵڶ���Ԫ����С���ڵ�����Ԫ�� */
            {

                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">='" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<='" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 2)/* һ�������ĵ�4��Ԫ��Ϊ2ʱ,�������ĺ���Ϊ���ڵڶ���Ԫ����С���ڵ�����Ԫ�� */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">'" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<='" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 3)/* һ�������ĵ�4��Ԫ��Ϊ3ʱ,�������ĺ���Ϊ����ڵڶ���Ԫ����С�ڵ�����Ԫ�� */
            {
                if ($terms[$i][1]!==NULL) $trm1 = $terms[$i][0] . ">='" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "' and ";else $trm1 = "";
                if ($terms[$i][2]!==NULL) $trm2 = $terms[$i][0] . "<'" . htmlspecialchars($terms[$i][2],ENT_QUOTES) . "' and ";else $trm2 = "";
            }
            else if ($terms[$i][3] == 4)/* һ�������ĵ�4��Ԫ��Ϊ4ʱ,�������ĺ���Ϊ���еڶ���Ԫ�� */
            {
                $trm1 = $terms[$i][0] . " LIKE '%" . htmlspecialchars($terms[$i][1],ENT_QUOTES) . "%' and ";
                $trm2 = "";
            }

            $trms = $trms . $trm1 . $trm2;
        }
        
        if ($orderby !="")
        {
			$resultorder = " order by " . $orderby;
            $orderby = " order by " . $orderby;
			
			if($asc)
			{
				$orderby .= " asc";
				$resultorder .= " desc";
			}
			else
			{
				$orderby .= " desc";
				$resultorder .= " asc";
			}
        }

		$where = '';
		if ($trms != "")
		{
			$where = " where " . substr($trms, 0, -5);
		}

/* debug: begin */
//if ($recordtype=='tb_film_main_sort' or $recordtype=='tb_film_sub_sort') echo("select count(*) from " . $recordtype . $where);
/* debug: end */

		$rslt = mssql_query ("select count(*) from " . $recordtype . $where);

		$n = mssql_result($rslt, 0, 0);

		if ($n == 0)
		{
			return 0;
		}

		if ($rows == '')
		{
			$rows = $n;
		}

		if ($offset >= $n)				/* ������¼�� */
		{
			return $n;
		}
			
		if (($offset + $rows) > $n)
		{
			$maxn = $n;
			$rows = $rows - ($offset + $rows - $n);
		}
		else
		{
			$maxn = $offset + $rows;
		}
		
        if ($trms != "")
        {
            $trms = " where " . substr($trms, 0, -5);
        }
        /*-- ��һ��һ��������ƴ����: end --*/

/* debug: begin */
//if ($recordtype=='tb_sheet_p_file_consumption') echo "select * from (select top ".$rows." * from "."(select top ".$maxn." * from " . $recordtype . $trms . $orderby.") as tb_tmp0".$resultorder.") as tb_tmp1 ".$orderby;
/* debug: end */

        $rslt = mssql_query ("select * from (select top ".$rows." * from "."(select top ".$maxn." * from " . $recordtype . $trms . $orderby.") as tb_tmp0".$resultorder.") as tb_tmp1 ".$orderby);

        /*-- ���������һ��һ������ӵ��������������: begin --*/
       	$num_rows = mssql_num_rows($rslt);
		$num_fields = mssql_num_fields($rslt);
        $result = array();

       	for($i = 0; $i < $num_rows; $i++)
		{
			for($j = 0; $j < $num_fields; $j++)
			{
				$field =  mssql_fetch_field($rslt, $j);
				$result[$i][$field->name] = mssql_result($rslt, $i, $j);
			}
		}
        /*-- ���������һ��һ������ӵ��������������: end --*/

        if ($rslt > 0)                             /* ���ݿ��ѯ���������ֵ */
        {
            return $n;
        }
        else                                       /* ���ݿ��ѯʧ�� */
        {
            return -1;
        }
	}
	
	
	/**********************************************************
	*  Update: ����һ����¼
	*
	*  @param $recordtype:	��¼������
	*  @param $index:		�����¼�¼������
	*  @param $record:		�����µ�����
	*  @return TRUE: �ɹ�; FALSE: ʧ��
	**********************************************************/
	function Update ($recordtype, $index, $record)
	{
		/*-- ������������µļ�¼�ӹ���sql���: begin --*/
        $rcd = "";
        
		$recordtype = 'tb_'.$recordtype;
		
        while (list ($rcrd, $rcrd_val) = each ($record))
        {
      	    $rcd = $rcd . " " . $rcrd . " " . "='" . htmlspecialchars($rcrd_val,ENT_QUOTES) . "',";
        }
        $rcd = substr ($rcd, 0, -1);
        /*-- ������������µļ�¼�ӹ���sql���: end --*/

        if ($index != NULL)
        {
	        /*-- ����������������ӹ���sql���: begin --*/
	        $ind = "";
	        while (list ($indx, $indx_val) = each ($index))
	        {
	            $ind = $ind . $indx . "='" . $indx_val . "' and ";
	        }
	        $ind = substr ($ind, 0, -5);
	        /*-- ����������������ӹ���sql���: end --*/
	
	        $rslt = mssql_query ("update " . $recordtype . " set " . $rcd . " where " .  $ind);
	    }
	    else
	    {
	        $rslt = mssql_query ("update " . $recordtype . " set " . $rcd);
	    }
	    
/* debug: begin */
//if ($recordtype=='tb_pay_setting') echo "update " . $recordtype . " set " . $rcd . " where " .  $ind;
/* debug: end */
        if ($rslt > 0)                                 /* ���ݿ��ѯ���������ֵ */
        {
            return TRUE;
        }
        else                                           /* ���ݿ��ѯʧ�ܷ���false */
        {
            return FALSE;
        }
	}

    /**********************************************************
    *  Exe: ��ʹ�����Ϻ���������ʱֱ��ִ��sql
    *
    *  @param $sql: SQL���
    *  @param $result: �������
    *  @return TRUE: �ɹ�; FALSE: ʧ��
    **********************************************************/
    function Exe ($viewname, &$result)
    {
        $array_sql_multi=explode(';',$viewname);
        for ($i=0;$i<count($array_sql_multi);++$i)
        {
            $rslt=mssql_query($array_sql_multi[$i]);
        }

		/*-- ���������һ��һ������ӵ��������������: begin --*/
		$result = array();
		if (is_resource ($rslt))
		{
			$num_rows = mssql_num_rows($rslt);
			$num_fields = mssql_num_fields($rslt);
			$result = array();

			for($i = 0; $i < $num_rows; $i++)
			{
				for($j = 0; $j < $num_fields; $j++)
				{
					$field =  mssql_fetch_field($rslt, $j);
					$result[$i][$field->name] = mssql_result($rslt, $i, $j);
				}
			}
		}
        /*-- ���������һ��һ������ӵ��������������: end --*/

        if ($rslt > 0)                             /* ���ݿ��ѯ���������ֵ */
        {
            return true;
        }
        else                                           /* ���ݿ��ѯʧ�ܷ���false */
        {
            return false;
        }
    }

	/**********************************************************
	*  GetTime: ��ȡDB Server�ĵ�ǰʱ��
	*
	*  @param $none
	*  @return unixʱ���
	**********************************************************/
	function GetTime ()
	{
		$rslt		= mssql_query ("select getdate()");
		$nowtime	= mssql_result($rslt, 0, 0);
		
		return strtotime($nowtime);
	}

	/**********************************************************
	*  GetLastID: ��ȡ���һ�α���ӵļ�¼��id
	*
	*  @param none
	*  @return ���һ�α���ӵļ�¼��id
	**********************************************************/
	function GetLastID ()
	{
		$rslt		= mssql_query ("select @@IDENTITY");
		$lastid		= mssql_result($rslt, 0, 0);
		
		return $lastid;
	}
}


$g_DataSource = new CDataSource();
$g_DataSource->Init();


/************************************************
 * @ DataSource.php v1.0 log @
 *
 * Revision 1.0.0.0     RD010     2005/07/16
 * create file
 * 
 ***********************************************/
?>