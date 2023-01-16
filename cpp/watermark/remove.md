
//1. Read a PDF file
doc = MakeObject<Document>(u"1.pdf");

//2. Read artifacts from first page
artifacts = doc->get_Pages()->idx_get(1)->get_Artifacts();

//3. If first artifact is a watermark, remove it
artifact = artifacts->idx_get(1);
if (artifact != nullptr && artifact->get_Subtype() == Aspose::Pdf::Artifact::ArtifactSubtype::Watermark)
    artifacts->Delete(artifact);

//4. save result pdf to file
doc->Save(u"remove_watermark.pdf", SaveFormat::Pdf);