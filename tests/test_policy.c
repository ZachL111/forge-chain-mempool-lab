#include "policy.h"
#include <assert.h>
#include <string.h>

int main(void) {
    Signal signal_case_1 = {89, 99, 10, 10, 5};
    assert(score_signal(signal_case_1) == 197);
    assert(strcmp(classify_signal(signal_case_1), "accept") == 0);
    Signal signal_case_2 = {89, 79, 8, 22, 6};
    assert(score_signal(signal_case_2) == 113);
    assert(strcmp(classify_signal(signal_case_2), "review") == 0);
    Signal signal_case_3 = {95, 93, 24, 8, 10};
    assert(score_signal(signal_case_3) == 183);
    assert(strcmp(classify_signal(signal_case_3), "accept") == 0);
    return 0;
}
