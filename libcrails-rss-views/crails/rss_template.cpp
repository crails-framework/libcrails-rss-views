#include "rss_template.hpp"
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace Crails;
using namespace std;

static string xml_escape_block(const string& value)
{
  return "<![CDATA[" + value + "]]>";
}

static string xml_escape(const string& data)
{
  string buffer;

  buffer.reserve(data.size());
  for(size_t pos = 0; pos != data.size(); ++pos) {
    switch(data[pos]) {
      case '<':  buffer.append("&lt;");        break;
      case '>':  buffer.append("&gt;");        break;
      default:   buffer.append(&data[pos], 1); break;
    }
  }
  return buffer;
}

static string rfc822_datetime(std::time_t value)
{
  std::tm tmdata = *gmtime(&value);
  stringstream stream;

  stream << put_time(&tmdata, "%a, %d %b %Y %H:%M:%S +0000");
  return stream.str();
}

string RssTemplate::xml_header(const string& encoding)
{
  return "<?xml version=\"1.0\" encoding=\"" + encoding + "\"?>";
}

string RssTemplate::title(const string& value)
{
  return "<title>" + xml_escape(value) + "</title>";
}

string RssTemplate::link(const string& value)
{
  return "<link>" + value + "</link>";
}

string RssTemplate::description(const string& value)
{
  return "<description>" + xml_escape_block(value) + "</description>";
}

string RssTemplate::description(Yieldable function)
{
  return description(function());
}

string RssTemplate::author(const string& value)
{
  return "<author>" + xml_escape(value) + "</author>";
}

string RssTemplate::category(const string& value)
{
  return "<category>" + xml_escape(value) + "</category>";
}

string RssTemplate::publication_date(std::time_t value)
{
  return "<pubDate>" + rfc822_datetime(value) + "</pubDate>";
}

string RssTemplate::last_build_date(std::time_t value)
{
  return "<lastBuildDate>" + rfc822_datetime(value) + "</lastBuildDate>";
}

string RssTemplate::guid(const string& value)
{
  if (value.find("http") == 0)
    return "<guid>" + xml_escape(value) + "</guid>";
  return "<guid isPermaLink=\"false\">" + xml_escape(value) + "</guid>";
}

string RssTemplate::guid(unsigned long long value)
{
  stringstream stream;

  stream << "<guid isPermaLink=\"false\">" << value << "</guid>";
  return stream.str();
}
