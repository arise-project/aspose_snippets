from Aspose.imaging import Image
from Aspose.Pdf import SaveFormat
from Aspose.Pdf import Rectangle
from Aspose.Pdf import PageSize
from Aspose.Pdf import Document
from System import TimeSpan
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")
aspose_imaging = clr.AddReference("../../lib/Aspose.Imaging.dll")


class jpg_to_docx  (object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):

        pathSource1 = "../../TestData/test.jpg"
        pathSource2 = "../../TestData/Second/test.jpg"

        # create empty pdf document
        doc = Document

        # set less memory usage with unload instead of fast performance
        doc.EnableObjectUnload = true

        # make list of files with images to merge
        images = [pathSource1, pathSource2]

        for fs in images:
            # add new page to pdf
            page = doc.Pages.Add()

            # setup page size to be A4
            page.SetPageSize(PageSize.A4.Width, PageSize.A4.Height)

            rect = Rectangle

            # load image from stream, it supports a lot of formats
            image = Image.load(fs)
            # read image dimensions to pdf page rectangle
            image.rect = Rectangle(0, 0, image.Width - 1, image.Heigh - 1)

            # add image to new pdf page
            page.AddImage(fs, rect)

        doc.Save("test.docx", SaveFormat.DocX)
