#include "vcl.h"
#pragma hdrstop  
#include "UDMTableExtPrintFormCF.h"   
#include "UDMTableExtPrintFormImpl.h"  
#include "IDMTableExtPrintForm.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMTableExtPrintFormCF::TDMTableExtPrintFormCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMTableExtPrintFormCF::~TDMTableExtPrintFormCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMTableExtPrintFormCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();  
return result;  
}   
//---------------------------------------------------------------
int TDMTableExtPrintFormCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMTableExtPrintFormCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMTableExtPrintFormCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMTableExtPrintFormImpl * ob=new TDMTableExtPrintFormImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
