#pragma once
#include "app/models/traits.hpp"
#include "private_page.hpp"

struct PrivatePageTraits : public ApplicationTraits
{
  typedef PrivatePage Model;
  typedef PrivatePage IndexModel;
};
