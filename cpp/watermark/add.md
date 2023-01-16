

//1. Read pdf file to Aspose Document
doc = MakeObject<Document>(u"1.pdf");

//2. Create artifact with image
artifact = MakeObject<WatermarkArtifact>();
artifact->SetImage(u"watermark.jpg");

//3. Set artifact position and rotation
artifact->set_ArtifactHorizontalAlignment(Aspose::Pdf::HorizontalAlignment::Center);
artifact->set_ArtifactVerticalAlignment(Aspose::Pdf::VerticalAlignment::Center);
artifact->set_Rotation(15);
artifact->set_Opacity(1);
artifact->set_IsBackground(true);

//4. Add artifact to first page
doc->get_Pages()->idx_get(1)->get_Artifacts()->Add(artifact);

//5. save result pdf to file
doc->Save(u"add_watermark.pdf",SaveFormat::Pdf);
