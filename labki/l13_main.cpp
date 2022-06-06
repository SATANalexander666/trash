#include "set.h"
#include<iostream>
using namespace std;

#define space ' '
#define indent '\n'
#define tab '\t'
#define alph_len 26
#define word_len 20

int main()
{
	char word[word_len];

	char seq_word_cur[word_len];
	char seq_word_max[word_len];

	bool word_set[2 * N];

	bool seq_cur_set[2 * N];

	int i = 0;
	int j = 0;

	int cnt = 0;
	int cnt_max = 0;

	char sym = 0;

	bool_set_clear(seq_cur_set);

	while((i = getchar()) != EOF)
	{
		if (i == space || i == indent || i == tab)
		{
			if (cnt == 0)
			{
				if (not_empty(seq_cur_set))
					cnt++;
				create_set(word, seq_cur_set);
				char_equate(seq_word_cur, word);
			}
			create_set(word, word_set);


			if (set_equal(word_set, seq_cur_set))
				cnt++;
			else
			{
				if (cnt > cnt_max)
				{
					cnt_max = cnt;
					char_equate(seq_word_max, seq_word_cur);
				}
				cnt = 0;
			}

			if (i == indent)
			{
				if (cnt > cnt_max)
				{
					cnt_max = cnt;
					char_equate(seq_word_max, seq_word_cur);
				}
				cnt = 0;

				cout << endl << "Max: " << cnt_max << "    First word: " << seq_word_max << endl;
			}

			char_clear(word);
			j = 0;
		}
		else
		{
			sym = i;
			word[j++] = sym;
		} 
	}
	return 0;
}





