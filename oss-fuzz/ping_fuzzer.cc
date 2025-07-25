/*
  Copyright @ 2018 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.

  You may not use this file except in compliance with the License.  You may
  obtain a copy of the License at

    https://imagemagick.org/script/license.php

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <cstdint>
#include <cstring>

#include <Magick++/Blob.h>
#include <Magick++/Image.h>

#include "utils.cc"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
  if (IsInvalidSize(Size,1))
    return(0);
  try
  {
    const Magick::Blob
      blob(Data, Size);

    Magick::Image
      image;

    image.ping(blob);
  }
#if defined(BUILD_MAIN)
  catch (Magick::Exception &e)
  {
    std::cout << "Exception when reading: " << e.what() << std::endl;
  }
#else
  catch (Magick::Exception)
  {
  }
#endif
  return(0);
}
