/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 11:57:00 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/23 18:34:56 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <wchar.h>
#include <locale.h>
#include "../libft.h"

#define ARG_MAX 25
#define CONVS_FI 7
#define LENM_FI 21

#define SPACE (1 << 0)
#define SHARP (1 << 1)
#define PLUS (1 << 2)
#define MINUS (1 << 3)
#define DOT (1 << 4)
#define ZERO (1 << 5)
#define PT (1 << 6)

#define _H (1 << 0)
#define _HH (1 << 1)
#define _L (1 << 2)
#define _LL (1 << 3)
#define _J (1 << 4)
#define _Z (1 << 5)

typedef struct	s_conv
{
	char		sp;
	int			lmod;
	int			flags;
	int			nbc;
	int			mfw;
	int			pre;
	int			err;
}				t_conv;

extern char		g_flags[];

size_t			u_numlen(t_conv *conv, uintmax_t n);
size_t			s_numlen(t_conv *conv, intmax_t n);
int				issigned(t_conv *conv);
int				isunsigned(t_conv *conv);
size_t			numlen(t_conv *conv, va_list *ap);

int				isfmt(char c);
int				isconvs(char c);
int				getlmod(const char *fmt, int isp);
int				getpre(const char *fmt, int isp);
int				getmfw(const char *fmt, int isp, int pre);

int				setflags(const char *fmt, t_conv *conv);
int				isnumconv(char c);
int				set_imfw(char *fmt, t_conv *conv, int isp);
void			check_stars(char *fmt, va_list *ap, t_conv *conv, int isp);
t_conv			*setconv(char **fmt, size_t nbc, va_list *ap);
size_t			get_paraml(t_conv *conv, va_list *ap);
char			*parse_fmt(char *fmt, va_list *ap, int *nbc);

int				reset_sd(t_conv *conv, int d, size_t len, char *s);
void			print_null(t_conv *conv);
void			print_s(t_conv *conv, va_list *ap, size_t len, int d);
int				check_wcs(wchar_t *ws, t_conv *conv, size_t *len, int locale);
void			print_wcs_pre(t_conv *conv, int d);
int				print_wcs_body(t_conv *conv, wchar_t *ws, int locale,
		int *lbyt);
void			print_wcs(t_conv *conv, va_list *ap, size_t len, int d);
void			print_c(t_conv *conv, va_list *ap, size_t len, int d);

int				print_pre_wc(t_conv *conv, wchar_t wc, int d, int locale);
void			print_wc(t_conv *conv, va_list *ap, size_t len, int d);
void			print_suf_wc(t_conv *conv, wchar_t wc, size_t len);
int				isunoct(t_conv *conv);
int				isunhex(t_conv *conv);
void			print_only_un(t_conv *conv, uintmax_t un);
void			print_pre_hex1(t_conv *conv, uintmax_t un, int *d, size_t len);
void			print_pre_hex2(t_conv *conv, uintmax_t un);
int				resetund(t_conv *conv, int d0, size_t len, intmax_t un);
void			print_pre_pt(t_conv *conv, uintmax_t un, size_t len, int tog);
int				print_un_spaces(t_conv *conv, int d0, size_t len, uintmax_t un);
void			print_pre_un(t_conv *conv, int *d, size_t len, uintmax_t un);
void			print_un(t_conv *conv, va_list *ap, size_t len, int d);
void			print_only_sn(t_conv *conv, intmax_t sn, size_t len);
int				ispositiv(t_conv *conv, intmax_t sn);
void			print_pre_sn(t_conv *conv, int *d, intmax_t sn, size_t len);
void			print_odd_case(t_conv *conv, intmax_t sn);
int				print_sn_spebody(t_conv *conv, intmax_t sn, size_t len, int d);
int				print_sn_regbody(t_conv *conv, intmax_t sn, size_t len, int d);
int				print_sn_body(t_conv *conv, intmax_t sn, size_t len, int d);
int				reset_snd(t_conv *conv, int d, size_t len);
void			print_sn(t_conv *conv, va_list *ap, size_t len, int d);
void			print_pre_nosp(t_conv *conv, int *d, size_t len);
void			print_nosp(t_conv *conv, size_t len, int d);
void			print_pt(t_conv *conv);

int				getws_d(t_conv *conv, wchar_t *ap, int locale);
int				setd(t_conv *conv, size_t len);
void			print_o(t_conv *conv, va_list *ap);
int				ft_printf(const char *fmt, ...);

#	endif
