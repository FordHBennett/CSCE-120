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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;

Network::Network()
{
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName)
{
  std::ifstream file;
  file.open(fileName);
  if (file.fail())
  {
    throw std::invalid_argument("std::invalid_argument");
  }
  while (!(file.eof()))
  {
    string user_post;
    if (file.eof())
    {
      file.close();
      throw std::runtime_error("std::invalid_argument");
    }
    file >> user_post;
    if (user_post == string{"User"})
    {
      try
      {
        string user;
        if (file.eof())
        {
          file.close();
          throw std::runtime_error("std::invalid_argument");
        }
        file >> user;
        addUser(user);
      }
      catch (const std::exception &e)
      {
        file.close();
        throw std::runtime_error("std::invalid_argument");
      }
    }
    else if (user_post == string{"Post"})
    {
      try
      {
        unsigned int post_id;
        string username;
        string post_text;
        if (file.eof())
        {
          file.close();
          throw std::runtime_error("std::invalid_argument");
        }
        file >> post_id;
        if (file.eof())
        {
          file.close();
          throw std::runtime_error("std::invalid_argument");
        }
        file >> username;
        if (file.eof())
        {
          file.close();
          throw std::runtime_error("std::invalid_argument");
        }
        std::getline(file,post_text);
        addPost(post_id, username, post_text);
      }
      catch (const std::exception &e)
      {
        file.close();
        throw std::runtime_error("std::invalid_argument");
      }
    }
    else
    {
      file.close();
      throw std::invalid_argument("std::invalid_argument");
    }
  }
  file.close();
}

void Network::addUser(string userName)
{
  // TODO(student): create user and add it to network
  string temp_name = userName;
  for (int i = 0; i < userName.length(); i++)
  {
    temp_name[i] = tolower(userName[i]);
  }
  for (size_t i = 0; i < users.size(); i++)
  {
    string temp = users.at(i)->getUserName();
    for (int i = 0; i < temp.length(); i++)
    {
      temp[i] = tolower(temp[i]);
    }
    if (temp == temp_name)
    {
      throw std::invalid_argument("std::invalid_argument");
    }
  }

  User *new_user = new User(userName);
  users.push_back(new_user);
  std::cout << "Added User " << userName << '\n';
  // delete new_user;
}

void Network::addPost(unsigned int postId, string userName, string postText)
{
  // TODO(student): create post and add it to network
  for (size_t i = 0; i < posts.size(); i++)
  {
    if (posts.at(i)->getPostId() == postId)
    {
      throw std::invalid_argument("std::invalid_argument");
    }
  }
  Post *new_post = new Post(postId, userName, postText);
  posts.push_back(new_post);
  for (size_t i = 0; i < users.size(); i++)
  {
    if (users.at(i)->getUserName() == userName)
    {
      users.at(i)->addUserPost(new_post);
      break;
    }
    else if (i == (users.size() - 1))
    {
      addUser(userName);
    }
  }
  vector<string> tag_canidates = new_post->findTags();
  for (size_t i = 0; i < tag_canidates.size(); i++)
  {
    try
    {
      Tag *new_tags = new Tag(tag_canidates.at(i));
      new_tags->addTagPost(new_post);
      tags.push_back(new_tags);
      // delete new_tags;
    }
    catch (const std::exception &e)
    {
      continue;
    }
  }
  // for (size_t i = 0; i < tags.size(); i++)
  // {
  //   for (size_t i = 0; i < tags.at(i)->getTagPosts().size(); i++)
  //   {
  //     std::cout << "Added Post " << tags.at(i)->getTagPosts().at(i)->getPostId() << " by " << tags.at(i)->getTagPosts().at(i)->getPostUser() << '\n';
  //   }
  // }
  std::cout << "Added Post " << postId << " by " << userName << '\n';
  // delete (new_post);
}

vector<Post *> Network::getPostsByUser(string userName)
{
  if (userName.size() == 0)
  {
    throw std::invalid_argument("std::invalid_argument");
  }

  for (size_t i = 0; i < posts.size(); i++)
  {
    if (users.at(i)->getUserName() == userName)
    {
      return users.at(i)->getUserPosts();
    }
    else if (i == (users.size() - 1))
    {
      throw std::invalid_argument("std::invalid_argument");
    }
  }
  return users.at(0)->getUserPosts();
}

vector<Post *> Network::getPostsWithTag(string tagName)
{
  if (tagName.size() == 0)
  {
    throw std::invalid_argument("std::invalid_argument");
  }
  for (size_t i = 0; i < tags.size(); i++)
  {
    if (tags.at(i)->getTagName() == tagName)
    {
      return tags.at(i)->getTagPosts();
    }
    else if (i == (tags.size() - 1))
    {
      throw std::invalid_argument("std::invalid_argument");
    }
  }
  return tags.at(0)->getTagPosts();
}

vector<string> Network::getMostPopularHashtag()
{
  if (tags.size() == 0)
  {
    throw std::invalid_argument("std::invalid_argument");
  }
  vector<string> most_popular_tag;
  most_popular_tag.push_back(tags.at(0)->getTagName());
  // for(size_t i = 1; i<tags.size();i++)
  // {
  //   if (tags.at(i)->getTagPosts().size()>most_popular_tag.at(0))
  //   {

  //   }
  // }
  return most_popular_tag;
}

/**
 * Destructor
 * Do not change; already implemented.
 */
Network::~Network()
{
  for (unsigned int i = 0; i < users.size(); ++i)
  {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i)
  {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i)
  {
    delete posts.at(i);
  }
}
