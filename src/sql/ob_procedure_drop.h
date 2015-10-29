#ifndef OCEANBASE_SQL_OB_PROCEDURE_DROP_H
#define OCEANBASE_SQL_OB_PROCEDURE_DROP_H
#include "sql/ob_single_child_phy_operator.h"
#include "ob_sql_session_info.h"
#include "common/dlist.h"

namespace oceanbase
{
	namespace sql
	{
		class ObPhysicalPlan;
		class ObProcedureDrop : public ObSingleChildPhyOperator
		{
		public:
			ObProcedureDrop();
			virtual ~ObProcedureDrop();
			virtual void reset();
			virtual void reuse();
			virtual int open();
			virtual int close();
			virtual ObPhyOperatorType get_type() const
			{
				return PHY_PROCEDURE_DROP;
			}
			virtual int64_t to_string(char* buf, const int64_t buf_len) const;
			virtual int get_row_desc(const common::ObRowDesc *&row_desc) const;
			virtual int get_next_row(const common::ObRow *&row);

			int set_proc_name(ObString &proc_name);/*设置存储过程名*/

			int set_delete_op(ObPhyOperator &delete_op);

			void set_if_exists(bool flag);
			bool if_exists();
		private:
			//disallow copy
			ObProcedureDrop(const ObProcedureDrop &other);
			ObProcedureDrop& operator=(const ObProcedureDrop &other);
			//function members

		private:
			ObString proc_name_;

			ObPhyOperator *delete_op_;
			bool  if_exists_;/*标识是否是if exists语法*/

		};



	}
}

#endif



