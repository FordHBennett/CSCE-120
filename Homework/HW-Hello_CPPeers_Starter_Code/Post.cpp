/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Post.h"

using std::string;
using std::vector;

Post::Post(unsigned int postId, string userName, string postText)
    : postId(postId), userName(userName), postText(postText)
{
  if (postId == 0 || userName == "" || postText == "")
  {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId()
{
  return postId;
}

string Post::getPostUser()
{
  return userName;
}

string Post::getPostText()
{
  return postText;
}

vector<string> Post::findTags()
{
  vector<string> tags;
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  for (size_t i = 0; i < postText.size(); i++)
  {
    //char punc_arr[4] = {'!', ',', '.', '?'};
    if (postText[i] == '#')
    {
      int whitespace =  postText.size() - 1;
      for(size_t j = i; j<postText.size();j++)
      {
        if(postText[j]==' ')
        {
          whitespace = j;
          break;
        }
      }
      bool is_tag_in_vector = false;
      string temp = postText.substr(i,(whitespace-i));
      for (int i = 0; i < temp.length(); i++)
      {
        if(std::ispunct(temp[i]))
        {
          temp.erase(i,i);
        }
        else
        {
          temp[i] = tolower(temp[i]);
        }
      }
      for (size_t k = 0; k < tags.size(); k++)
      {
        if (tags.at(k) == temp)
        {
          is_tag_in_vector = true;
        }
      }
      if (!(is_tag_in_vector))
      {
        tags.push_back(tempa);
      }
    }
  }
  return tags;
}
