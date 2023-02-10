#ifndef ITERATOR_TAGS_HPP
#define ITERATOR_TAGS_HPP

namespace ft
{


struct output_iterator_tag
{

};

struct input_iterator_tag: public output_iterator_tag
{

};

struct forward_iterator_tag: public input_iterator_tag
{

};

struct bidirection_iterator_tag: public forward_iterator_tag
{

};

struct random_access_iterator_tag: public bidirection_iterator_tag
{

};

}

#endif