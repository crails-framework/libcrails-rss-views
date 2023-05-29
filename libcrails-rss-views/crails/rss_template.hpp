#ifndef  CRAILS_RSS_TEMPLATE_HPP
# define CRAILS_RSS_TEMPLATE_HPP

# include <crails/template.hpp>
# include <ctime>
# include <functional>

namespace Crails
{
  class RssTemplate : public Template
  {
  public:
    typedef std::function<std::string()> Yieldable;

    RssTemplate(const Renderer& renderer, RenderTarget& target, SharedVars& vars) :
      Template(renderer, target, vars)
    {
    }

    static std::string xml_header(const std::string& encoding);
    static std::string title(const std::string&);
    static std::string link(const std::string&);
    static std::string description(const std::string&);
    static std::string description(Yieldable);
    static std::string author(const std::string&);
    static std::string category(const std::string&);
    static std::string publication_date(std::time_t);
    static std::string last_build_date(std::time_t);
    static std::string guid(const std::string&);
    static std::string guid(unsigned long long);
  };
}

#endif
