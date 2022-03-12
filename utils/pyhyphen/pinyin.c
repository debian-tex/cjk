/*

  This is the file pinyin.c of the CJK macro package ver. 4.8.5
  (16-Oct-2021).

  Use this file to generate a hyphenation input file for patgen.

  Usage:

    pinyin > pinyin.dic

 */

/*
  Copyright (C) 1994-2021  Werner Lemberg <wl@gnu.org>
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program in doc/COPYING; if not, write to the Free
  Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
  MA 02110-1301 USA
 */

#include <stdio.h>


/* A list of all Chinese syllables.  We use latin-1 encoding for the
   `umlaut u' character.

   In the array below, syllables starting with `a', `e', or `u' are marked
   with a leading exclamation mark, which we filter out later on to ensure
   that those syllables are omitted on the right side.  If written without a
   line break, an apostrophe must be inserted before such syllables, e.g.,

     Tien'anmen

   However, if there is a line break, the apostrophe disappears:

     Tien-
     anmen

   This situation can't be handled by patgen; instead, a solution to this
   problem can be provided by TeX with

     \discretionary{-}{}{'}

   The babel support file (`pinyin.ldf') provides "' as a shorthand for this
   situation.
 */

char *py[] =
{
  "!a",
  "!ai",
  "!an",
  "!ang",
  "!ao",
  "ba",
  "bai",
  "ban",
  "bang",
  "bao",
  "bei",
  "ben",
  "beng",
  "bi",
  "bian",
  "biao",
  "bie",
  "bin",
  "bing",
  "bo",
  "bu",
  "ca",
  "cai",
  "can",
  "cang",
  "cao",
  "ce",
  "cen",
  "ceng",
  "cha",
  "chai",
  "chan",
  "chang",
  "chao",
  "che",
  "chen",
  "cheng",
  "chi",
  "chong",
  "chou",
  "chu",
  "chuai",
  "chuan",
  "chuang",
  "chui",
  "chun",
  "chuo",
  "ci",
  "cong",
  "cou",
  "cu",
  "cuan",
  "cui",
  "cun",
  "cuo",
  "da",
  "dai",
  "dan",
  "dang",
  "dao",
  "de",
  "dei",
  "deng",
  "di",
  "dian",
  "diao",
  "die",
  "ding",
  "diu",
  "dong",
  "dou",
  "du",
  "duan",
  "dui",
  "dun",
  "duo",
  "!e",
  "!ei",
  "!en",
  "!eng",
  "!er",
  "fa",
  "fan",
  "fang",
  "fei",
  "fen",
  "feng",
  "fiao",
  "fo",
  "fou",
  "fu",
  "ga",
  "gai",
  "gan",
  "gang",
  "gao",
  "ge",
  "gei",
  "gen",
  "geng",
  "gong",
  "gou",
  "gu",
  "gua",
  "guai",
  "guan",
  "guang",
  "gui",
  "gun",
  "guo",
  "ha",
  "hai",
  "han",
  "hang",
  "hao",
  "he",
  "hei",
  "hen",
  "heng",
  "hong",
  "hou",
  "hu",
  "hua",
  "huai",
  "huan",
  "huang",
  "hui",
  "hun",
  "huo",
  "ji",
  "jia",
  "jian",
  "jiang",
  "jiao",
  "jie",
  "jin",
  "jing",
  "jiong",
  "jiu",
  "ju",
  "juan",
  "jue",
  "jun",
  "ka",
  "kai",
  "kan",
  "kang",
  "kao",
  "ke",
  "kei",
  "ken",
  "keng",
  "kong",
  "kou",
  "ku",
  "kua",
  "kuai",
  "kuan",
  "kuang",
  "kui",
  "kun",
  "kuo",
  "la",
  "lai",
  "lan",
  "lang",
  "lao",
  "le",
  "lei",
  "leng",
  "li",
  "lia",
  "lian",
  "liang",
  "liao",
  "lie",
  "lin",
  "ling",
  "liu",
  "long",
  "lou",
  "lu",
  "luan",
  "lun",
  "luo",
  "l�",
  "l�e",
  "ma",
  "mai",
  "man",
  "mang",
  "mao",
  "me",
  "mei",
  "men",
  "meng",
  "mi",
  "mian",
  "miao",
  "mie",
  "min",
  "ming",
  "miu",
  "mo",
  "mou",
  "mu",
  "na",
  "nai",
  "nan",
  "nang",
  "nao",
  "ne",
  "nei",
  "nen",
  "neng",
  "ni",
  "nian",
  "niang",
  "niao",
  "nie",
  "nin",
  "ning",
  "niu",
  "nong",
  "nou",
  "nu",
  "nuan",
  "nuo",
  "n�",
  "n�e",
  "!o",
  "!ou",
  "pa",
  "pai",
  "pan",
  "pang",
  "pao",
  "pei",
  "pen",
  "peng",
  "pi",
  "pian",
  "piao",
  "pie",
  "pin",
  "ping",
  "po",
  "pou",
  "pu",
  "qi",
  "qia",
  "qian",
  "qiang",
  "qiao",
  "qie",
  "qin",
  "qing",
  "qiong",
  "qiu",
  "qu",
  "quan",
  "que",
  "qun",
  "ran",
  "rang",
  "rao",
  "re",
  "ren",
  "reng",
  "ri",
  "rong",
  "rou",
  "ru",
  "ruan",
  "rui",
  "run",
  "ruo",
  "sa",
  "sai",
  "san",
  "sang",
  "sao",
  "se",
  "sen",
  "seng",
  "sha",
  "shai",
  "shan",
  "shang",
  "shao",
  "she",
  "shei",
  "shen",
  "sheng",
  "shi",
  "shou",
  "shu",
  "shua",
  "shuai",
  "shuan",
  "shuang",
  "shui",
  "shun",
  "shuo",
  "si",
  "song",
  "sou",
  "su",
  "suan",
  "sui",
  "sun",
  "suo",
  "ta",
  "tai",
  "tan",
  "tang",
  "tao",
  "te",
  "tei",
  "teng",
  "ti",
  "tian",
  "tiao",
  "tie",
  "ting",
  "tong",
  "tou",
  "tu",
  "tuan",
  "tui",
  "tun",
  "tuo",
  "wa",
  "wai",
  "wan",
  "wang",
  "wei",
  "wen",
  "weng",
  "wo",
  "wu",
  "xi",
  "xia",
  "xian",
  "xiang",
  "xiao",
  "xie",
  "xin",
  "xing",
  "xiong",
  "xiu",
  "xu",
  "xuan",
  "xue",
  "xun",
  "ya",
  "yan",
  "yang",
  "yao",
  "ye",
  "yi",
  "yin",
  "ying",
  "yo",
  "yong",
  "you",
  "yu",
  "yuan",
  "yue",
  "yun",
  "za",
  "zai",
  "zan",
  "zang",
  "zao",
  "ze",
  "zei",
  "zen",
  "zeng",
  "zha",
  "zhai",
  "zhan",
  "zhang",
  "zhao",
  "zhe",
  "zhei",
  "zhen",
  "zheng",
  "zhi",
  "zhong",
  "zhou",
  "zhu",
  "zhua",
  "zhuai",
  "zhuan",
  "zhuang",
  "zhui",
  "zhun",
  "zhuo",
  "zi",
  "zong",
  "zou",
  "zu",
  "zuan",
  "zui",
  "zun",
  "zuo"
};


int main(void)
{
  size_t i, j;
  size_t size = sizeof (py) / sizeof (char*);

  /* Now we loop through all possible syllable combinations. */

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (py[j][0] == '!')
        continue;

      if (py[i][0] == '!')
        printf("%s-%s\n", py[i] + 1, py[j]);
      else
        printf("%s-%s\n", py[i], py[j]);
    }
  }

  return 0;
}
