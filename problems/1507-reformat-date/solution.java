class Solution {
    public String reformatDate(String date) {
        String[] parts = date.split(" ");
        String day = parts[0].replaceAll("[^0-9]", "");
        String month = "";
        switch (parts[1]) {
            case "Jan":
                month = "01";
                break;
            case "Feb":
                month = "02";
                break;
            case "Mar":
                month = "03";
                break;
            case "Apr":
                month = "04";
                break;
            case "May":
                month = "05";
                break;
            case "Jun":
                month = "06";
                break;
            case "Jul":
                month = "07";
                break;
            case "Aug":
                month = "08";
                break;
            case "Sep":
                month = "09";
                break;
            case "Oct":
                month = "10";
                break;
            case "Nov":
                month = "11";
                break;
            case "Dec":
                month = "12";
                break;
        }
        String year = parts[2];
        return year + "-" + month + "-" + (day.length() == 1 ? "0" + day : day);
    }
}