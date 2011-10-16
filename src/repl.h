/*
  This file is part of the PhantomJS project from Ofi Labs.

  Copyright (C) 2011 Ivan De Marino <ivan.de.marino@gmail.com>

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef REPL_H
#define REPL_H

#include <QWebFrame>

#include "phantom.h"
#include "terminal.h"

/**
 * REPL. Read–Eval–Print Loop.
 *
 * This class realises the REPL functionality within PhantomJS.
 * It uses a QSocketNotifier to listed on the STDIN and act upon user input.
 * More info about REPL: http://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop
 *
 * TODO - Proper error handling (JS stack trace?)
 * TODO - Terminal output coloring on supporting Shells (maybe)
 * TODO/QUESTION - How to separate STDOUT and STDERR more effectively?
 *
 * On creation it will create a QSocketNotifier, and attach it in READ to the STDIN.
 * In this way the class Phantom can delegate this functionality completely.
 */
class REPL: public QObject
{
    Q_OBJECT

public:
    REPL(QWebFrame *webframe, Phantom *parent);

private slots:
    void dataReadyOnStdIn(const int &id);

private:
    QWebFrame *m_webframe;
    Phantom *m_parentPhantom;
    Terminal *m_terminal;
};

#endif // REPL_H
