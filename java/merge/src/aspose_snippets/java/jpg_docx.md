//1. create empty pdf document
doc = new com.aspose.pdf.Document();

//2. make list of files with images to merge
List<String> images = Arrays.asList(new String[]{"1.jpg", "2.jpg"});

//3. add image to new pdf page
//add new page to pdf
//load image from stream using Aspose Imaging, it supports a lot of formats
//read image dimensions to pdf page rectangle
for (String fs : images) {
    page = doc.getPages().add();
    image = com.aspose.imaging.Image.load(fs);
    page.addImage(fs, new com.aspose.pdf.Rectangle(0, 0, image.getWidth() - 1, image.getHeight() - 1));

//4. save result pdf to file
doc.save("Merger_jpg_docx.docx", com.aspose.pdf.SaveFormat.DocX);
