/**
 * (C) 2010-2012 Alibaba Group Holding Limited.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * Version: $Id$
 *
 * ob_drop_table.h
 *
 * Authors:
 *   Zhifeng YANG <zhuweng.yzf@taobao.com>
 *
 */
#ifndef _OB_DROP_TABLE_H
#define _OB_DROP_TABLE_H 1
#include "sql/ob_no_children_phy_operator.h"
#include "common/ob_strings.h"
namespace oceanbase
{
  namespace mergeserver
  {
    class ObMergerRootRpcProxy;
  } // end namespace mergeserver

  namespace sql
  {
    class ObDropTable: public ObNoChildrenPhyOperator
    {
      public:
        ObDropTable();
        virtual ~ObDropTable();
        virtual void reset();
        virtual void reuse();
        // init
        void set_rpc_stub(mergeserver::ObMergerRootRpcProxy* rpc);

        void set_if_exists(bool if_exists);
        int add_table_name(const common::ObString &tname);

        /// execute the insert statement
        virtual int open();
        virtual int close();
        virtual ObPhyOperatorType get_type() const { return PHY_DROP_TABLE; }
        virtual int64_t to_string(char* buf, const int64_t buf_len) const;

        /// @note always return OB_ITER_END
        virtual int get_next_row(const common::ObRow *&row);
        /// @note always return OB_NOT_SUPPORTED
        virtual int get_row_desc(const common::ObRowDesc *&row_desc) const;
      private:
        // types and constants
      private:
        // disallow copy
        ObDropTable(const ObDropTable &other);
        ObDropTable& operator=(const ObDropTable &other);
        // function members
      private:
        // data members
        bool if_exists_;
        common::ObStrings tables_;
        mergeserver::ObMergerRootRpcProxy* rpc_;
    };

    inline int ObDropTable::get_next_row(const common::ObRow *&row)
    {
      row = NULL;
      return common::OB_ITER_END;
    }

    inline int ObDropTable::get_row_desc(const common::ObRowDesc *&row_desc) const
    {
      row_desc = NULL;
      return common::OB_NOT_SUPPORTED;
    }

    inline void ObDropTable::set_rpc_stub(mergeserver::ObMergerRootRpcProxy* rpc)
    {
      rpc_ = rpc;
    }

  } // end namespace sql
} // end namespace oceanbase

#endif /* _OB_DROP_TABLE_H */
