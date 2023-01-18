```cpp

//1. Read a PDF file
doc = MakeObject<Document>(u"1.pdf");

//2. Read artifacts from first page
artifacts = doc->get_Pages()->idx_get(1)->get_Artifacts();

//3. Check if there is a watermark
artifact = artifacts->idx_get(1);
if (artifact != nullptr && artifact->get_Subtype() == Aspose::Pdf::Artifact::ArtifactSubtype::Watermark)

//4. Get image from watermark artifact
fs = System::IO::File::OpenWrite(u"get_watermark.jpg");
artifact->get_Image()->Save(fs);

```