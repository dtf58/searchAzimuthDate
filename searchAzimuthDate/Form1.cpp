#include "pch.h"
#include "Form1.h"

namespace CppCLRWinFormsProject {

    Form1::Form1(void)
    {
        InitializeComponent();
        XmlDocument^ xmlDoc = gcnew XmlDocument();
        try
        {
            xmlDoc->Load("searchAzimuthDate.xml");
            XmlNodeList^ items = xmlDoc->GetElementsByTagName("Location");
            long num = items->Count;
            for (long i = 0; i < num; ++i)
            {
                XmlNode^ item = items->Item(i);
                double longitude = Convert::ToDouble(item->Attributes->GetNamedItem("longitude")->Value);
                double latitude = Convert::ToDouble(item->Attributes->GetNamedItem("latitude")->Value);
                String^ strLocation = String::Format("{0,8:F4} {1} {2,8:F4} {3} {4}\r\n", longitude, item->Attributes->GetNamedItem("side")->Value,
                    latitude, item->Attributes->GetNamedItem("hemis")->Value, item->Attributes->GetNamedItem("name")->Value);
                listLocation->Items->Add(strLocation);
            }
            if (num > 0)
            {
                listLocation->SelectedIndex = 0;
            }
            items = xmlDoc->GetElementsByTagName("StartDate");
            num = items->Count;
            if (num > 0)
            {
                XmlNode^ item = items->Item(0);
                startDate->Text = item->InnerText;
            }
            items = xmlDoc->GetElementsByTagName("SearchTime");
            num = items->Count;
            if (num > 0)
            {
                XmlNode^ item = items->Item(0);
                searchTime->Text = item->InnerText;
            }
            items = xmlDoc->GetElementsByTagName("SearchAzimuth");
            num = items->Count;
            if (num > 0)
            {
                XmlNode^ item = items->Item(0);
                searchAzi->Text = item->InnerText;
            }
            items = xmlDoc->GetElementsByTagName("CelesticalObject");
            num = items->Count;
            for (long i = 0; i < num; ++i)
            {
                XmlNode^ item = items->Item(i);
                String^ strCelObj = String::Format("{0} {1}\r\n",
                    item->Attributes->GetNamedItem("RA")->Value,
                    item->Attributes->GetNamedItem("DE")->Value);
                searchObject->Text=strCelObj;
            }
        }
        catch (...)
        {

        }
    }

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    Form1::~Form1()
    {
        if (components)
        {
            delete components;
        }
    }

    System::Void Form1::Search_Click(System::Object^ sender, System::EventArgs^ e)
    {
    }

    System::Void Form1::clearResult_Click(System::Object^ sender, System::EventArgs^ e)
    {
        out_textBox->Clear();
    }
}