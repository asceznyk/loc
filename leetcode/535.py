import base64

from urllib.parse import urlparse

class Codec:
  tinyHost = "https://tinyurl.com/"

  def encode(self, longUrl:str) -> str:
    return self.tinyHost + base64.b64encode(bytes(longUrl.encode('ascii'))).decode('utf-8')

  def decode(self, shortUrl: str) -> str:
    return base64.b64decode(shortUrl.replace(self.tinyHost, "")).decode('utf-8')

