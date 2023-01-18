```java

doc = new com.aspose.pdf.Document("1.pdf");

if(doc.getPages().get_Item(1).getArtifacts().get_Item(1).getSubtype() == com.aspose.pdf.Artifact.ArtifactSubtype.Watermark)
{
    fs = new FileOutputStream("get_watermark.jpg");
    doc.getPages().get_Item(1).getArtifacts().get_Item(1).getImage().save(fs);
    fs.flush();
    fs.close();
}

```