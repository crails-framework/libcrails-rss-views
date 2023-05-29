#ifndef  CRAILS_RSS_RENDERER_HPP
# define CRAILS_RSS_RENDERER_HPP

# include <crails/renderer.hpp>

namespace Crails
{
  class RssRenderer : public Renderer
  {
  public:
    bool can_render(const std::string& accept_header, const std::string& view) const override;
    void render_template(const std::string& view, RenderTarget&, SharedVars& vars) const override;
  };
}

#endif
