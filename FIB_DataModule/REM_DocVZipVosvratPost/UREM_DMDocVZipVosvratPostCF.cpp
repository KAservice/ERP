#include "vcl.h"
#pragma hdrstop  
#include "UREM_DMDocVZipVosvratPostCF.h"   
#include "UREM_DMDocVZipVosvratPostImpl.h"  
#include "IREM_DMDocVZipVosvratPost.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TREM_DMDocVZipVosvratPostCF::TREM_DMDocVZipVosvratPostCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TREM_DMDocVZipVosvratPostCF::~TREM_DMDocVZipVosvratPostCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TREM_DMDocVZipVosvratPostCF::kanQueryInterface(REFIID id_interface, void**ppv)  
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
int TREM_DMDocVZipVosvratPostCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TREM_DMDocVZipVosvratPostCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TREM_DMDocVZipVosvratPostCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TREM_DMDocVZipVosvratPostImpl * ob=new TREM_DMDocVZipVosvratPostImpl();  
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
