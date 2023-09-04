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
#include "User.h"

using std::string;
using std::vector;

User::User(string userName): userName(userName) {
  if((userName.size()==0))
  {
    throw std::invalid_argument("user constructor: invalid parameter values");
  }
  for(size_t i = 0; i < userName.size();i++)
  {
    if((userName[i]>'z')||(userName[i]<'a'))
    {
      throw std::invalid_argument("User constructor: invalid parameter values");
    }
  }
}

string User::getUserName() {
  // TODO(student): implement getter
  // try
  // {
  //   if(islower(userName[0]))
  //   {
  //     throw std::invalid_argument("std::invalid_argument");
  //   }
  // }
  // catch(const std::exception& e)
  // {
  //   throw std::invalid_argument("std::invalid_argument");
  // }
  // for(size_t i = 0; i<userName.size();i++)
  // {
  //   if(isupper(userName[i]))
  //   {
  //     break;
  //   }
  //   if(i==(userName.size()-1))
  //   {
  //     throw std::invalid_argument("std::invalid_argument");
  //   }
  // }
  return userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if(post == nullptr)
  {
    throw std::invalid_argument("std::invalid_argument");
  }
  else
  {
    userPosts.push_back(post);
  }
}
