/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_EVAL_DEBUGGER_CMD_EVAL_H_
#define incl_HPHP_EVAL_DEBUGGER_CMD_EVAL_H_

#include "hphp/runtime/debugger/debugger_command.h"

namespace HPHP { namespace Eval {
///////////////////////////////////////////////////////////////////////////////

class CmdEval : public DebuggerCommand {
public:
  CmdEval() : DebuggerCommand(KindOfEval), m_bypassAccessCheck(false) {
    m_version = 1;
  }

  virtual void onClient(DebuggerClient &client);
  virtual bool onServer(DebuggerProxy &proxy);

  virtual void handleReply(DebuggerClient &client);
  bool failed() { return m_failed; }

protected:
  virtual void sendImpl(DebuggerThriftBuffer &thrift);
  virtual void recvImpl(DebuggerThriftBuffer &thrift);

private:
  String m_output;
  int m_frame;
  bool m_bypassAccessCheck;
  bool m_failed;
};

///////////////////////////////////////////////////////////////////////////////
}}

#endif // incl_HPHP_EVAL_DEBUGGER_CMD_EVAL_H_
