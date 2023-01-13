
//1. create empty pdf document
System::SharedPtr<Document> outputDoc = MakeObject<Document>();

//2. make list of files with images to merge
String images[] = {u"1.jpg", u"2.jpg"};

//3. add new page to pdf
// read image dimensions to pdf page rectangle
// add image to new pdf page
for (String fs : images) {
    auto page = outputDoc->get_Pages()->Add();
    page->AddImage(fs, new Aspose::Pdf::Rectangle(0, 0, 700, 1000));
}

//4. save result docx to file
outputDoc->Save(u"Merger_jpg_docx.docx", SaveFormat::DocX);
