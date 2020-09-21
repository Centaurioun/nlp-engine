#include "lite/nlp_engine.h"

#ifdef LINUX
int main(
#else
_tmain(
#endif
   int argc,
   _TCHAR *argv[],
   _TCHAR *envp[]
   )
{
    _TCHAR analyzer[1001];
    _TCHAR input[1001];
    _TCHAR output[1001];

    _stprintf(analyzer,"%s",_T("taiparse"));
    output[0] = '\0';

    _t_cout << _T("[analyzer name: ") << analyzer << _T("]") << endl;
    _t_cout << _T("[input: ") << input << _T("]") << endl;
     
    NLP_ENGINE *nlpEngine = new NLP_ENGINE(analyzer);
    _t_cout << _T("post constructor: ") << input << _T("]") << endl;

    NLP_ENGINE *nlpEngine2 = new NLP_ENGINE("noop");
    _t_cout << _T("post constructor: ") << input << _T("]") << endl;

    _stprintf(input,"%s",_T("The quick brown fox jumped over the lazy dog."));
    nlpEngine->analyze(input,1000,output,1000);
    _t_cout << _T("[output: ") << output << _T("]") << endl;
    output[0] = '\0';
    nlpEngine2->analyze(input,1000,output,1000);
    _t_cout << _T("[output2: ") << output << _T("]") << endl;
    output[0] = '\0';

    _stprintf(input,"%s",_T("All good people must come to the aid of their country."));
    nlpEngine->analyze(input,1000,output,1000);
    _t_cout << _T("[output: ") << output << _T("]") << endl;
    output[0] = '\0';
    nlpEngine2->analyze(input,1000,output,1000);
    _t_cout << _T("[output2: ") << output << _T("]") << endl;
    output[0] = '\0';

    nlpEngine2->close();
    delete nlpEngine2;

    nlpEngine->close();
    delete nlpEngine;
}