#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	value;
	int	index;
	int	target;
}				t_stack;

int			trunc_up(int n);
int			ft_count_words(char const *s, char c);
char		*ft_make_words(char *word, char const *s, int k, int word_ln);
char		**ft_split_words(char **out, char const *s, char c, int word_ct);
char		**ft_split(char const *s, char c);
int			count_elems(t_stack *stack);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		rev_rotate(t_stack *stack);
void		push(t_stack *from, t_stack *to);
int			is_sorted(t_stack *stack);
int			calc_the_cost(t_stack node, int base_len, int comp_len);
void		swap_a(t_stack *stack);
void		swap_b(t_stack *stack);
void		swap_both(t_stack *stack_a, t_stack *stack_b);
void		push_a(t_stack *from, t_stack *to);
void		push_b(t_stack *from, t_stack *to);
void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		rev_rotate_a(t_stack *stack);
void		rev_rotate_b(t_stack *stack);
void		rev_rotate_both(t_stack *stack_a, t_stack *stack_b);
int			find_index_of_min_value(t_stack *stack);
int			find_cheapest(t_stack *base, t_stack *compare);
int			find_index_of_max(t_stack *stack);
int			find_index_of_closest_bigger(int number, t_stack *stack);
void		set_targets_ascend(t_stack *stack_a, t_stack *stack_b);
void		sort_three(t_stack *stack);
void		sort_four(t_stack *stack_a, t_stack *stack_b);
void		rev_both_down(t_stack *base, t_stack *compare, int base_index);
void		rev_a_down_b_up(t_stack *stack_a, t_stack *stack_b,
				int lowest_cost);
void		rev_a_up_b_down(t_stack *stack_a, t_stack *stack_b,
				int lowest_cost);
void		rev_both_up(t_stack *base, t_stack *compare, int base_index);
void		reverse_polarity(t_stack *stack_a, t_stack *stack_b,
				int super_index);
void		print_turk_thing(t_stack *stack_a, t_stack *stack_b);
void		rotate_end(t_stack *stack);
void		turk_thing(t_stack *stack_a, t_stack *stack_b);
long		ft_atoi(const char *str);
int			ft_isalnum(char *c);
int			ft_repeat(char **list, int len);
void		free_list(char **list, int len);
void		spell_check(char **list, int len, int ac);
char		**write_args_to_list(int ac, char **av, int *amount_of_elements);
void		set_stacks(t_stack *stack_a, t_stack *stack_b,
				char **list, int len);
void		sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif