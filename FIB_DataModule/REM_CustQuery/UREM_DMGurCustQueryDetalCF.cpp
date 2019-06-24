#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMGurCustQueryDetalCF.h"   
#include "UREM_DMGurCustQueryDetalImpl.h"  
#include "IREM_DMGurCustQueryDetal.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMGurCustQueryDetalCF::TREM_DMGurCustQueryDetalCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMGurCustQueryDetalCF::~TREM_DMGurCustQueryDetalCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMGurCustQueryDetalCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_DMGurCustQueryDetalCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMGurCustQueryDetalCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMGurCustQueryDetalCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMGurCustQueryDetalImpl * ob=new TREM_DMGurCustQueryDetalImpl();  
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
