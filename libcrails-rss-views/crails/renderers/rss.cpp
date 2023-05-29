#include "rss.hpp"

using namespace std;
using namespace Crails;

bool RssRenderer::can_render(const std::string& accept_header, const std::string& view) const
{
  if (accept_header.find("application/rss+xml")  != std::string::npos)
    return templates.find(view) != templates.end();
  return (false);
}

void RssRenderer::render_template(const std::string& view, RenderTarget& target, SharedVars& vars) const
{
  auto tpl = templates.find(view);

  target.set_header("Content-Type", "application/rss+xml");
  tpl->second(*this, target, vars);
}
