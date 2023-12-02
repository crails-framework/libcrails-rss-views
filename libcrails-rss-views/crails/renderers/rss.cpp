#include "rss.hpp"

using namespace std;
using namespace Crails;

const vector<string>& RssRenderer::get_mimetypes() const
{
  static const vector<string> mimetypes{
    "application/rss+xml", "application/atom+xml", "application/rdf+xml"
  };
  return mimetypes;
}

void RssRenderer::render_template(const std::string& view, RenderTarget& target, SharedVars& vars) const
{
  auto tpl = templates.find(view);

  target.set_header("Content-Type", "application/rss+xml");
  tpl->second(*this, target, vars);
}
