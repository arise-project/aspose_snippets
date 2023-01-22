//1. create empty pdf document
auto outputDoc = MakeObject<Aspose::Pdf::Document>();

//2. Display and save the pages
// Get the CLSID of the PNG encoder.
Gdiplus::Image  multi(L"1.tiff");
GetEncoderClsid(L"image/png", &encoderClsid);
multi.SelectActiveFrame(&pageGuid, 0);
multi.Save(L"Page0.png", &encoderClsid, NULL);
multi.SelectActiveFrame(&pageGuid, 1);
multi.Save(L"Page1.png", &encoderClsid, NULL);

//3. add new page to document
// create new image into document
// set image source to memory stream
// add document image to specific page
for (auto path : { u"Page0.png", u"Page1.png" }) {
        
        auto page = outputDoc->get_Pages()->Add();
        auto image = MakeObject<Aspose::Pdf::Image>();
        auto stream = System::IO::File::Create(path);
        image->set_ImageStream(stream);
        page->get_Paragraphs()->Add(image);
    }

//4. save result pdf to file
outputDoc->Save(u"Merger_tiff_pdf.pdf", Aspose::Pdf::SaveFormat::Pdf);

```