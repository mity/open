/* Simple open command line utility.
 * Copyright 2014-2023 Martin Mitáš
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <stdio.h>
#include <windows.h>
#include <shellapi.h>


#ifndef UNICODE
    #error This needs to be built with Unicode enabled.
    /* E.g. with gcc this usually means options -municode -DUNICODE -D_UNICODE. */
#endif


int
wmain(int argc, WCHAR** argv)
{
    SHELLEXECUTEINFO sei;
    int i;

    memset(&sei, 0, sizeof(SHELLEXECUTEINFO));
    sei.cbSize = sizeof(sei);
    sei.fMask = SEE_MASK_FLAG_DDEWAIT;
    sei.nShow = SW_SHOWNORMAL;
    sei.lpVerb = L"open";

    for(i = 1; i < argc; i++) {
        int j, n;

        /* Translate '/' potentially propagated from some unix shells to '\\' */
        n = wcslen(argv[i]);
        for(j = 0; j < n; j++) {
            if(argv[i][j] == L'/')
                argv[i][j] = L'\\';
        }

        sei.lpFile = argv[i];
        ShellExecuteEx(&sei);
    }

    return 0;
}
