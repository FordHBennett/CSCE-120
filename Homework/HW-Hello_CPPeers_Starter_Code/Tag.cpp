/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName) : tagName(tagName) {
  if((tagName.length()<3)||(tagName[0]!='#'))
  {
    throw std::invalid_argument("Tag constructor: invalid parameter values");
  }
  for(int i = 1; i<tagName.size();i++ )
  {
if(!((tagName[i]>='a')||(tagName[i]<='z')))
  {
    throw std::invalid_argument("Tag constructor: invalid parameter values");
  }
  }

  char punc_arr[4] = {'!', ',', '.', '?'};
  for(size_t i = 2;i<tagName.length();i++)
  {
    if(((tagName[i-1]==punc_arr[0])||(tagName[i-1]==punc_arr[1])||(tagName[i-1]==punc_arr[2])||(tagName[i-1]==punc_arr[3]))&&((tagName[i]==punc_arr[0])||(tagName[i]==punc_arr[1])||(tagName[i]==punc_arr[2])||(tagName[i]==punc_arr[3])))
    {
      throw std::invalid_argument("Tag constructor: invalid parameter values");
    }
  }
}

string Tag::getTagName() {
  // TODO(student): implement getter
  return tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return tagPosts;
}

void Tag::addTagPost(Post* post) {
  if(post==nullptr)
  {
    throw std::invalid_argument("std::invalid_argument");
  }
  else{
    tagPosts.push_back(post);
  }
}
